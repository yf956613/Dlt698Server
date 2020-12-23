#ifndef DLT698_ARRAY_H
#define DLT698_ARRAY_H

#include "data.h"

namespace Dlt698 {

template<typename T>
class Array : public Data
{
public:
    Array(Data *parent = nullptr);
    Array(Data &other, Data *parent = nullptr);
    Array(Array<T> &other, Data *parent = nullptr);
    Array<T>& operator =(const Array<T>& other);
    Array<T>& operator =(Array<Data> &other);

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
Array<T>::Array(Data *parent)
    : Data(parent)
{
    this->setDataType(this->getTypeByName(typeid(Array<Data>).name()));
}

template<typename T>
Array<T>::Array(Data &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

template<typename T>
Array<T>::Array(Array<T> &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

template<typename T>
Array<T> &Array<T>::operator =(const Array<T> &other)
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
Array<T> &Array<T>::operator =(Array<Data> &other)
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
Data &Array<T>::operator =(Data &other)
{
    Array<Data>* temp = dynamic_cast<Array<Data>*>(&other);
    if(temp != NULL) {
        *this = *temp;
    }
    return *this;
}

template<typename T>
void Array<T>::addData(T *data)
{
    data->setParent(this);
    m_data.push_back(data);
}

template<typename T>
list<T *> Array<T>::data() const
{
    return m_data;
}

template<typename T>
void Array<T>::clear()
{
    this->childsClear();
    m_data.clear();
}

template<typename T>
void Array<T>::decode(const vector<BYTE> &res, size_t &pos)
{
    if(typeid(T) != typeid(Data))
        return;

    BYTE num = res.at(pos ++);
    while(num --) {
        m_data.push_back(dynamic_cast<T*>(this->decodeProxy(res, pos)));
    }
}

template<typename T>
void Array<T>::encode(vector<BYTE> &res)
{
    BYTE temp = m_data.size();
    this->baseEncode(res, temp);
    for(auto k : m_data) {
        k->encodeProxy(res);
    }
}

template<typename T>
Data *Array<T>::clone(Data *parent)
{
    return new Array<T>(*this, parent);
}

}

#endif // ARRAY_H
