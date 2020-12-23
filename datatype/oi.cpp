#include "oi.h"

using namespace Dlt698;


long_unsigned_c OI::data() const
{
    return m_data;
}

void OI::setData(const long_unsigned_c &data)
{
    m_data = data;
}

OI::OI(long_unsigned_c data)
    : m_data(data)
{

}

void OI::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, m_data);
}

void OI::encode(vector<BYTE> &res)
{
    this->baseEncode(res, m_data);
}
