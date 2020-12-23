#include "dlt698ctrldomain.h"

Dlt698CtrlDomain::Dlt698CtrlDomain()
{
    memset(&this->CtrlDomain, 0, sizeof(_tCONTROLDOMAIN));
}

void Dlt698CtrlDomain::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, &this->CtrlDomain, sizeof(_tCONTROLDOMAIN));
}

void Dlt698CtrlDomain::encode(vector<BYTE> &res)
{
    this->baseEncode(res, &this->CtrlDomain, sizeof(_tCONTROLDOMAIN));
}

string Dlt698CtrlDomain::toString()
{
    DltStringBuffer buffer;
    buffer.append("控制域", this->byteToString((BYTE*)&this->CtrlDomain, sizeof(_tCONTROLDOMAIN)));
    return buffer.toString();
}

eFunc Dlt698CtrlDomain::getFunc() const
{
    return (eFunc)CtrlDomain.func;
}

void Dlt698CtrlDomain::setFunc(const eFunc &value)
{
    CtrlDomain.func = value;
}

BYTE Dlt698CtrlDomain::getRes() const
{
    return CtrlDomain.res;
}

void Dlt698CtrlDomain::setRes(const BYTE &value)
{
    CtrlDomain.res = value;
}

eFrame Dlt698CtrlDomain::getFrame() const
{
    return (eFrame)CtrlDomain.frame;
}

void Dlt698CtrlDomain::setFrame(const eFrame &value)
{
    CtrlDomain.frame = value;
}

ePrm Dlt698CtrlDomain::getPRM() const
{
    return (ePrm)CtrlDomain.PRM;
}

void Dlt698CtrlDomain::setPRM(const ePrm &value)
{
    CtrlDomain.PRM = value;
}

eDir Dlt698CtrlDomain::getDIR() const
{
    return (eDir)CtrlDomain.DIR;
}

void Dlt698CtrlDomain::setDIR(const eDir &value)
{
    CtrlDomain.DIR = value;
}
