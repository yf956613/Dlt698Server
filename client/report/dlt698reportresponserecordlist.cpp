#include "dlt698reportresponserecordlist.h"

Dlt698ReportResponseRecordList::Dlt698ReportResponseRecordList()
{
    this->piid.reset(new Dlt698Piid());
    this->oads.reset(new Row<Oad>());
}

void Dlt698ReportResponseRecordList::decode(const vector<BYTE> &res, size_t &pos)
{
    piid->decode(res, pos);
    oads->decode(res, pos);
}

void Dlt698ReportResponseRecordList::encode(vector<BYTE> &res)
{
    this->piid->encode(res);
    oads->encode(res);
}

shared_ptr<Dlt698Piid> Dlt698ReportResponseRecordList::getPiid() const
{
    return piid;
}

void Dlt698ReportResponseRecordList::setPiid(const shared_ptr<Dlt698Piid> &value)
{
    piid = value;
}

shared_ptr<Row<Oad> > Dlt698ReportResponseRecordList::getOads() const
{
    return oads;
}

void Dlt698ReportResponseRecordList::setOads(const shared_ptr<Row<Oad> > &value)
{
    oads = value;
}

