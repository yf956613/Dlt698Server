#include "oad.h"

using namespace Dlt698;

Oad::Oad(Data *parent)
    : Data(parent)
{
    this->setDataType(this->getTypeByName(typeid(*this).name()));
}

Oad::Oad(Data &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

Oad &Oad::operator =(Oad &other)
{
    m_oi = other.m_oi;
    m_OAD = other.m_OAD;
}

void Oad::decode(const vector<BYTE> &res, size_t &pos)
{
    m_oi.decode(res, pos);
    this->baseDecode(res, pos, &m_OAD, sizeof(_tOAD));
}

void Oad::encode(vector<BYTE> &res)
{
    m_oi.encode(res);
    this->baseEncode(res, &m_OAD, sizeof(_tOAD));
}

Data *Oad::clone(Data *parent)
{
    return new Oad(*this, parent);
}

Data &Oad::operator =(Data &other)
{
    return Dlt698::dynamicCopy(*this, other);
}

unsigned_c Oad::getAttrId() const
{
    return m_OAD.attrId;
}

void Oad::setAttrId(const unsigned_c &value)
{
    m_OAD.attrId = value;
}

unsigned_c Oad::getAttrFea() const
{
    return m_OAD.attrFea;
}

void Oad::setAttrFea(const unsigned_c &value)
{
    m_OAD.attrFea = value;
}

unsigned_c Oad::getElemIdx() const
{
    return m_OAD.elemIdx;
}

void Oad::setElemIdx(const unsigned_c &value)
{
   m_OAD.elemIdx = value;
}

OI Oad::getOi()
{
    return m_oi;
}

void Oad::setOi(OI &oi)
{
    m_oi = oi;
}
