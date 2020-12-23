#include "road.h"

using namespace Dlt698;

Road::Road()
{
    m_oad.reset(new Oad());
    m_poad.reset(new Row<Oad>());
}

void Road::decode(const vector<BYTE> &res, size_t &pos)
{
    m_oad->decode(res, pos);
    m_poad->decode(res, pos);
}

void Road::encode(vector<BYTE> &res)
{
    m_oad->encode(res);
    m_poad->encode(res);
}

shared_ptr<Oad> Road::oad() const
{
    return m_oad;
}

void Road::setOad(const shared_ptr<Oad> &oad)
{
    m_oad = oad;
}

shared_ptr<Row<Oad> > Road::poad() const
{
    return m_poad;
}

void Road::setPoad(const shared_ptr<Row<Oad> > &poad)
{
    m_poad = poad;
}


