#include "dlt698getresponsenormallist.h"

Dlt698GetResponseNormalList::Dlt698GetResponseNormalList()
{
    this->piid.reset(new Dlt698PiidAcd());
    this->results.reset(new Row<ResultNormal>());
}

void Dlt698GetResponseNormalList::decode(const vector<BYTE> &res, size_t &pos)
{
    piid->decode(res, pos);
    results->decode(res, pos);
}

void Dlt698GetResponseNormalList::encode(vector<BYTE> &res)
{
    piid->encode(res);
    results->encode(res);
}

shared_ptr<Dlt698PiidAcd> Dlt698GetResponseNormalList::getPiid() const
{
    return piid;
}

void Dlt698GetResponseNormalList::setPiid(const shared_ptr<Dlt698PiidAcd> &value)
{
    piid = value;
}

shared_ptr<Row<ResultNormal> > Dlt698GetResponseNormalList::getResults() const
{
    return results;
}

void Dlt698GetResponseNormalList::setResults(const shared_ptr<Row<ResultNormal> > &value)
{
    results = value;
}

