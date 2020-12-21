#ifndef DATAARRAY_H
#define DATAARRAY_H

#include "data.h"
#include "databasic.h"

namespace Dlt698 {

template<typename T>
class DataArray : public Data
{
public:
    DataArray(Data *parent = nullptr);
    DataArray(Data &other, Data *parent = nullptr);
    DataArray(DataArray<T> &other, Data *parent = nullptr);
    DataArray<T>& operator =(const DataArray<T>& other);
    DataArray<T>& operator =(DataArray<Data> &other);

    void addData(T *data);
    list<T *> data() const;

    void clear();

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    // Data interface
public:
    virtual Data *clone(Data *parent) override;

    virtual Data &operator =(Data &other) override;

private:
    list<T*> m_data;

};

template<typename T>
DataArray<T>::DataArray(Data *parent)
    : Data(parent)
{
    this->setDataType(this->getTypeByName(typeid(DataArray<Data>).name()));
}

template<typename T>
DataArray<T>::DataArray(Data &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

template<typename T>
DataArray<T>::DataArray(DataArray<T> &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

template<typename T>
DataArray<T> &DataArray<T>::operator =(const DataArray<T> &other)
{
    if(this == &other)
        return *this;
    this->clear();
    list<T *> childs = other.data();
    for(auto k : childs) {
        T* temp = new T(*k);
        temp->setParent(this);
        m_data.push_back(temp);
    }
    return *this;
}

template<typename T>
DataArray<T> &DataArray<T>::operator =(DataArray<Data> &other)
{
    this->clear();
    list<Data *> childs = other.data();
    for(auto k : childs) {
        T* temp = new T(*k);
        temp->setParent(this);
        m_data.push_back(temp);
    }
    return *this;
}

template<typename T>
Data &DataArray<T>::operator =(Data &other)
{
    DataArray<Data>* temp = dynamic_cast<DataArray<Data>*>(&other);
    if(temp != NULL) {
        *this = *temp;
    }
    return *this;
}

template<typename T>
void DataArray<T>::addData(T *data)
{
    data->setParent(this);
    m_data.push_back(data);
}

template<typename T>
list<T *> DataArray<T>::data() const
{
    return m_data;
}

template<typename T>
void DataArray<T>::clear()
{
    this->childsClear();
    m_data.clear();
}

template<typename T>
void DataArray<T>::decode(const vector<BYTE> &res, size_t &pos)
{
    if(typeid(T) != typeid(Data))
        return;

    BYTE num = res.at(pos ++);
    while(num --) {
        m_data.push_back(dynamic_cast<T*>(this->decodeProxy(res, pos)));
    }
}

template<typename T>
void DataArray<T>::encode(vector<BYTE> &res)
{
    BYTE temp = m_data.size();
    this->baseEncode(res, temp);
    for(auto k : m_data) {
        k->encodeProxy(res);
    }
}

template<typename T>
Data *DataArray<T>::clone(Data *parent)
{
    return new DataArray<T>(*this, parent);
}

}

#endif // DATAARRAY_H
