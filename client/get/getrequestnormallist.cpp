#include "getrequestnormallist.h"

using namespace Dlt698;

GetRequestNormalList::GetRequestNormalList()
{
    m_piid.reset(new Dlt698Piid());
    m_oads.reset(new Row<Oad>());
}

void GetRequestNormalList::decode(const vector<BYTE> &res, size_t &pos)
{
    m_piid->decode(res, pos);
    m_oads->decode(res, pos);
}

void GetRequestNormalList::encode(vector<BYTE> &res)
{
    m_piid->encode(res);
    m_oads->encode(res);
}

shared_ptr<Dlt698Piid> GetRequestNormalList::piid() const
{
    return m_piid;
}

void GetRequestNormalList::setPiid(const shared_ptr<Dlt698Piid> &piid)
{
    m_piid = piid;
}

shared_ptr<Row<Oad> > GetRequestNormalList::oads() const
{
    return m_oads;
}

void GetRequestNormalList::setOads(const shared_ptr<Row<Oad> > &oads)
{
    m_oads = oads;
}
