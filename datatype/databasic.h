#ifndef DATABASIC_H
#define DATABASIC_H

#include "data.h"

namespace Dlt698 {

template<typename T>
class DataBasic : public Data
{
public:
    DataBasic(Data *parent = nullptr);
    DataBasic(DataBasic<T> &other, Data *parent = nullptr);
    DataBasic(Data &other, Data *parent = nullptr);
    DataBasic(const T &other);
    DataBasic<T>& operator =(const DataBasic<T> &other);

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    T data() const;
    void setData(const T &data);

private:
    T m_data;

    // Data interface
public:
    virtual Data *clone(Data *parent) override;

    virtual Data &operator =(Data &other) override;
};


template<typename T>
DataBasic<T>::DataBasic(Data *parent)
    : Data(parent)
{
    this->setDataType(this->getTypeByName(typeid(*this).name()));
}

template<typename T>
DataBasic<T>::DataBasic(DataBasic<T> &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

template<typename T>
DataBasic<T>::DataBasic(Data &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

template<typename T>
DataBasic<T>::DataBasic(const T &other)
    : Data()
{
    m_data = other;
}

template<typename T>
DataBasic<T> &DataBasic<T>::operator =(const DataBasic<T> &other)
{
    if(this != &other)
        m_data = other.data();
    return *this;
}

template<typename T>
Data &DataBasic<T>::operator =(Data &other)
{
    return Dlt698::dynamicCopy(*this, other);
}

template<typename T>
void DataBasic<T>::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, m_data);
}

template<typename T>
void DataBasic<T>::encode(vector<BYTE> &res)
{
    this->baseEncode(res, m_data);
}

template<typename T>
T DataBasic<T>::data() const
{
    return m_data;
}

template<typename T>
void DataBasic<T>::setData(const T &data)
{
    m_data = data;
}

template<typename T>
Data *DataBasic<T>::clone(Data *parent)
{
    return new DataBasic<T>(*this, parent);
}

}

#endif // DATABASIC_H
