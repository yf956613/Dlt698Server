#include "getrequestnormal.h"

using namespace Dlt698;

void GetRequestNormal::decode(const vector<BYTE> &res, size_t &pos)
{
    m_piid->decode(res, pos);
    m_oad->decode(res, pos);
}

void GetRequestNormal::encode(vector<BYTE> &res)
{
    m_piid->encode(res);
    m_oad->encode(res);

}

GetRequestNormal::GetRequestNormal()
{
    m_oad.reset(new Oad());
    m_piid.reset(new Dlt698Piid());
}

shared_ptr<Oad> GetRequestNormal::oad() const
{
    return m_oad;
}

void GetRequestNormal::setOad(const shared_ptr<Oad> &oad)
{
    m_oad = oad;
}

shared_ptr<Dlt698Piid> GetRequestNormal::piid() const
{
    return m_piid;
}

void GetRequestNormal::setPiid(const shared_ptr<Dlt698Piid> &piid)
{
    m_piid = piid;
}
