#include "reportresponselist.h"

using namespace Dlt698;

ReportResponseList::ReportResponseList()
{
    m_piid.reset(new Dlt698PiidAcd());
    m_oads.reset(new Row<Oad>());
}

shared_ptr<Row<Oad> > ReportResponseList::oads() const
{
    return m_oads;
}

void ReportResponseList::setOads(const shared_ptr<Row<Oad> > &oads)
{
    m_oads = oads;
}

shared_ptr<Dlt698PiidAcd> ReportResponseList::piid() const
{
    return m_piid;
}

void ReportResponseList::setPiid(const shared_ptr<Dlt698PiidAcd> &piid)
{
    m_piid = piid;
}

void ReportResponseList::decode(const vector<BYTE> &res, size_t &pos)
{
    m_piid->decode(res, pos);
    m_oads->decode(res, pos);
}

void ReportResponseList::encode(vector<BYTE> &res)
{
    m_piid->encode(res);
    m_oads->encode(res);
}
