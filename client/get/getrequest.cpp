#include "getrequest.h"
#include "getrequestnormal.h"
#include "getrequestnormallist.h"

using namespace Dlt698;

GetRequest::GetRequest(eGetRequest type)
    : m_type(type)
{
    m_body.reset(this->bodyInstance(type));
}

eGetRequest GetRequest::type() const
{
    return m_type;
}

void GetRequest::setType(const eGetRequest &type)
{
    m_type = type;
    m_body.reset(this->bodyInstance(type));
}

shared_ptr<Dlt698Proctol> GetRequest::body() const
{
    return m_body;
}

Dlt698Proctol *GetRequest::bodyInstance(eGetRequest type) const
{
    switch (type) {
    case _GetRequestNormal:
        return new GetRequestNormal();
        break;
    case _GetRequestNormalList:
        return new GetRequestNormalList();
        break;
    case _GetRequestRecord:
        break;
    case _GetRequestRecordList:
        break;
    case _GetRequestNext:
        break;
    case _GetRequestMD5:
        break;
    }
    return new Dlt698Proctol();
}

void GetRequest::decode(const vector<BYTE> &res, size_t &pos)
{
    this->enumDecode(res, pos, m_type);
    m_body.reset(this->bodyInstance(m_type));
    m_body->decode(res, pos);
}

void GetRequest::encode(vector<BYTE> &res)
{
    this->enumEncode(res, m_type);
    m_body->encode(res);
}
