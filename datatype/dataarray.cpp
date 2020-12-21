//#include "dataarray.h"

//using namespace Dlt698;

//DataArray::DataArray(Data *parent)
//    : Data(parent)
//{
//    this->setDataType(this->getTypeByName(typeid(*this).name()));
//}

//DataArray::DataArray(const DataArray &other)
//    : Data(other)
//{
//    *this = other;
//}

//DataArray &DataArray::operator =(const DataArray &other)
//{
//    if(this == &other)
//        return *this;
//    this->clear();
//    list<Data *> childs = other.data();
//    for(auto k : childs) {
//        m_data.push_back(k->clone(this));
//    }
//    return *this;
//}

//DataArray *DataArray::addData(Data *data)
//{
//    m_data.push_back(data);
//    return this;
//}

//list<Data *> DataArray::data() const
//{
//    return m_data;
//}

//void DataArray::clear()
//{
//    this->childsClear();
//    m_data.clear();
//}

//void DataArray::decode(const vector<BYTE> &res, size_t &pos)
//{
//    BYTE num = res.at(pos ++);
//    while(num --) {
//        m_data.push_back(this->decodeProxy(res, pos));
//    }
//}

//void DataArray::encode(vector<BYTE> &res)
//{
//    BYTE temp = m_data.size();
//    this->baseEncode(res, temp);
//    for(auto k : m_data) {
//        k->encodeProxy(res);
//    }
//}

//Data *DataArray::clone(Data *parent)
//{
//    Data* res = new DataArray(*this);
//    res->setParent(parent);
//    return res;
//}
