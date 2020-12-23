#include "dlt698getresponsenormal.h"

using namespace Dlt698;

Dlt698GetResponseNormal::Dlt698GetResponseNormal()
{
    this->piid.reset(new Dlt698PiidAcd());
    this->result.reset(new ResultNormal());
}

shared_ptr<Dlt698::ResultNormal> Dlt698GetResponseNormal::getResult() const
{
    return result;
}

void Dlt698GetResponseNormal::setResult(const shared_ptr<ResultNormal> &value)
{
    result = value;
}

shared_ptr<Dlt698PiidAcd> Dlt698GetResponseNormal::getPiid() const
{
    return piid;
}

void Dlt698GetResponseNormal::setPiid(const shared_ptr<Dlt698PiidAcd> &value)
{
    piid = value;
}

void Dlt698GetResponseNormal::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->result->decode(res, pos);
}

void Dlt698GetResponseNormal::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    this->result->encode(res);
}
