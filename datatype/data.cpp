#include "data.h"
#include "datafactory.h"
#include <QDebug>

using namespace Dlt698;

unordered_map<std::string, eDataType> Data::m_nameType = unordered_map<std::string, eDataType>();

Data::Data(Data *parent)
    : m_parent(parent)
{
    this->setParent(parent);
}

Data::Data(Data &other, Data *parent)
    : m_parent(parent)
{
    this->setParent(parent);
    *this = other;
}

Data &Data::operator=(Data &other)
{
    if(this == &other)
        return *this;
    m_dataType = other.dataType();
    return *this;
}

Data::~Data()
{
    for(auto k : m_childs) {
        delete k;
    }
}

Data *Data::clone(Data *parent)
{
    Data *res = new Data(*this);
    res->setParent(parent);
    return res;
}

eDataType Data::dataType() const
{
    return m_dataType;
}

void Data::setDataType(const eDataType &dataType)
{
    m_dataType = dataType;
}

Data *Data::decodeProxy(const vector<BYTE> &res, size_t &pos)
{
    eDataType type = (eDataType)res.at(pos ++);
    Data* data = DataFactory::instance().dataClone(type, this);
    data->decode(res, pos);
    return data;
}

void Data::encodeProxy(vector<BYTE> &res)
{
    this->baseEncode(res, (BYTE)m_dataType);
    this->encode(res);
}

void Data::addNameType(const std::string &name, eDataType type)
{
    m_nameType[name] = type;
}

eDataType Data::getTypeByName(const std::string &name)
{
    try{
        return m_nameType.at(name);
    }
    catch(std::out_of_range) {
        return t_null;
    };
}

Data *Data::getParent() const
{
    return m_parent;
}

void Data::setParent(Data *parent)
{
    if(m_parent != nullptr) {
        m_parent->m_childs.remove(this);
    }
    m_parent = parent;
    if(m_parent != nullptr) {
        m_parent->m_childs.push_back(this);
    }
}

void Data::childsClear()
{
    Data temp;
    for(auto k : m_childs) {
        k->setParent(&temp);
    }
    m_childs.clear();
}

list<Data *> Data::childs() const
{
    return m_childs;
}

const list<Data *> &Data::childs()
{
    return m_childs;
}
