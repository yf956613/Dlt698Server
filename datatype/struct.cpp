#include "struct.h"
#include "datafactory.h"

using namespace Dlt698;

Struct::Struct(Data *parent)
    : Data(parent)
{
    this->setDataType(this->getTypeByName(typeid(*this).name()));
}

Struct::Struct(Struct &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

Struct::Struct(Data &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

Struct &Struct::operator =(const Struct &other)
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

Data &Struct::operator =(Data &other)
{
    Struct* temp = dynamic_cast<Struct*>(&other);
    if(temp != NULL) {
        *this = *temp;
    }
    return *this;
}

void Struct::decode(const vector<BYTE> &res, size_t &pos)
{
    BYTE num = res.at(pos ++);
    while(num --) {
        this->decodeProxy(res, pos);
    }
}

void Struct::encode(vector<BYTE> &res)
{
    list<Data*> childs = this->childs();
    BYTE num = childs.size();
    this->baseEncode(res, num);
    for(auto k : childs) {
        k->encodeProxy(res);
    }
}

Data *Struct::clone(Data *parent)
{
    return new Struct(*this, parent);
}

