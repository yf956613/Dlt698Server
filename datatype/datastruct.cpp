#include "datastruct.h"
#include "datafactory.h"

using namespace Dlt698;

DataStruct::DataStruct(Data *parent)
    : Data(parent)
{
    this->setDataType(this->getTypeByName(typeid(*this).name()));
}

DataStruct::DataStruct(DataStruct &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

DataStruct::DataStruct(Data &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

DataStruct &DataStruct::operator =(const DataStruct &other)
{
    if(this == &other)
        return *this;

    list<Data*> childs = this->childs();
    list<Data*> children = other.childs();
    auto im = childs.begin(), io = children.begin();
    while(im != childs.end() && io != children.end()) {
        *(*im) = *(*io);
        ++ im;
        ++ io;
    }
    return *this;
}

Data &DataStruct::operator =(Data &other)
{
    DataStruct* temp = dynamic_cast<DataStruct*>(&other);
    if(temp != NULL) {
        *this = *temp;
    }
    return *this;
}

void DataStruct::decode(const vector<BYTE> &res, size_t &pos)
{
    BYTE num = res.at(pos ++);
    while(num --) {
        this->decodeProxy(res, pos);
    }
}

void DataStruct::encode(vector<BYTE> &res)
{
    list<Data*> childs = this->childs();
    BYTE num = childs.size();
    this->baseEncode(res, num);
    for(auto k : childs) {
        k->encodeProxy(res);
    }
}

Data *DataStruct::clone(Data *parent)
{
    return new DataStruct(*this, parent);
}
