#ifndef DLT698_BASIC_H
#define DLT698_BASIC_H

#include "data.h"

namespace Dlt698 {

template<typename T>
class Basic : public Data
{
public:
    Basic(Data *parent = nullptr);
    Basic(Basic<T> &other, Data *parent = nullptr);
    Basic(Data &other, Data *parent = nullptr);
    Basic(const T &other);
    Basic<T>& operator =(const Basic<T> &other);

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
Basic<T>::Basic(Data *parent)
    : Data(parent)
{
    this->setDataType(this->getTypeByName(typeid(*this).name()));
    m_data = 0;
}

template<typename T>
Basic<T>::Basic(Basic<T> &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

template<typename T>
Basic<T>::Basic(Data &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

template<typename T>
Basic<T>::Basic(const T &other)
    : Data()
{
    m_data = other;
}

template<typename T>
Basic<T> &Basic<T>::operator =(const Basic<T> &other)
{
    if(this != &other)
        m_data = other.data();
    return *this;
}

template<typename T>
Data &Basic<T>::operator =(Data &other)
{
    return Dlt698::dynamicCopy(*this, other);
}

template<typename T>
void Basic<T>::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, m_data);
}

template<typename T>
void Basic<T>::encode(vector<BYTE> &res)
{
    this->baseEncode(res, m_data);
}

template<typename T>
T Basic<T>::data() const
{
    return m_data;
}

template<typename T>
void Basic<T>::setData(const T &data)
{
    m_data = data;
}

template<typename T>
Data *Basic<T>::clone(Data *parent)
{
    return new Basic<T>(*this, parent);
}

}

#endif // BASIC_H
