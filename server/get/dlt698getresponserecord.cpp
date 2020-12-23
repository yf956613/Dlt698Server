#include "dlt698getresponserecord.h"

Dlt698GetResponseRecord::Dlt698GetResponseRecord()
{
    this->piid.reset(new Dlt698PiidAcd());
    this->result.reset(new ResultRecord());
}

void Dlt698GetResponseRecord::decode(const vector<BYTE> &res, size_t &pos)
{
    this->piid->decode(res, pos);
    this->result->decode(res, pos);
}

void Dlt698GetResponseRecord::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    this->result->encode(res);
}

shared_ptr<Dlt698PiidAcd> Dlt698GetResponseRecord::getPiid() const
{
    return piid;
}

void Dlt698GetResponseRecord::setPiid(const shared_ptr<Dlt698PiidAcd> &value)
{
    piid = value;
}

shared_ptr<ResultRecord> Dlt698GetResponseRecord::getResult() const
{
    return result;
}

void Dlt698GetResponseRecord::setResult(const shared_ptr<ResultRecord> &value)
{
    result = value;
}
