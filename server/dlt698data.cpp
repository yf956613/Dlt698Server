#include "dlt698data.h"
#include <QDebug>

Dlt698::Data *Dlt698Data::getChild() const
{
    if(m_data.childs().empty())
        return nullptr;
    return m_data.childs().front();
}

void Dlt698Data::setChild(Dlt698::Data *data)
{
    m_data.childsClear();
    data->setParent(&m_data);
}

void Dlt698Data::decode(const vector<BYTE> &res, size_t &pos)
{
    m_data.childsClear();
    m_data.decodeProxy(res, pos);
}

void Dlt698Data::encode(vector<BYTE> &res)
{
    if(this->getChild() == nullptr)return;
    this->getChild()->encodeProxy(res);
}
