#include "dar.h"

using namespace Dlt698;

DAR::DAR(eDAR data)
    : m_data(data)
{

}

void DAR::decode(const vector<BYTE> &res, size_t &pos)
{
    m_data = (eDAR)res[pos ++];
}

void DAR::encode(vector<BYTE> &res)
{
    this->baseEncode(res, (BYTE)m_data);
}
