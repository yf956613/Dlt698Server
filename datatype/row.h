#ifndef DLT698_ROW_H
#define DLT698_ROW_H

#include "dlt698proctol.h"

namespace Dlt698 {

template<typename T>
class Row : public Dlt698Proctol
{
public:

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    vector<shared_ptr<T> > data() const;
    void setData(const vector<shared_ptr<T> > &data);

    void addData(shared_ptr<T> data);
    shared_ptr<T> getData(size_t idx);

private:
    vector<shared_ptr<T>> m_data;
};

template<typename T>
void Row<T>::decode(const vector<BYTE> &res, size_t &pos)
{
    BYTE num = res[pos ++];
    while(num --) {
        shared_ptr<T> temp(new T());
        temp->decode(res, pos);
        m_data.push_back(temp);
    }
}

template<typename T>
void Row<T>::encode(vector<BYTE> &res)
{
    this->baseEncode(res, (BYTE)res.size());
    for(auto &k : m_data) {
        k->encode(res);
    }
}

template<typename T>
vector<shared_ptr<T> > Row<T>::data() const
{
    return m_data;
}

template<typename T>
void Row<T>::setData(const vector<shared_ptr<T> > &data)
{
    m_data = data;
}

template<typename T>
void Row<T>::addData(shared_ptr<T> data)
{
    m_data.push_back(data);
}

template<typename T>
shared_ptr<T> Row<T>::getData(size_t idx)
{
    try {
        return m_data.at(idx);
    }
    catch(out_of_range) {
        return shared_ptr<T>();
    }
}

}

#endif // ROW_H
