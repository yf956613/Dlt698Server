#include "dlt698getresponserecordlist.h"

Dlt698GetResponseRecordList::Dlt698GetResponseRecordList()
{
    piid.reset(new Dlt698PiidAcd());
    results.reset(new Row<ResultRecord>());
}

void Dlt698GetResponseRecordList::decode(const vector<BYTE> &res, size_t &pos)
{
    piid->decode(res, pos);
    results->decode(res, pos);
}

void Dlt698GetResponseRecordList::encode(vector<BYTE> &res)
{
    piid->encode(res);
    results->encode(res);
}

shared_ptr<Dlt698PiidAcd> Dlt698GetResponseRecordList::getPiid() const
{
    return piid;
}

void Dlt698GetResponseRecordList::setPiid(const shared_ptr<Dlt698PiidAcd> &value)
{
    piid = value;
}

shared_ptr<Row<ResultRecord> > Dlt698GetResponseRecordList::getResults() const
{
    return results;
}

void Dlt698GetResponseRecordList::setResults(const shared_ptr<Row<ResultRecord> > &value)
{
    results = value;
}



