#include "dlt698clientapdu.h"
#include "connect/dlt698connectrequest.h"
#include "get/getrequest.h"
#include "report/dlt698reportresponse.h"

Dlt698ClientApdu::Dlt698ClientApdu(eClientAPDU type, bool_c tagExist)
    : sevType(type), timeTagExist(tagExist)
{
    this->body.reset(this->bodyInstance(type));
    this->timeTag.reset(new Dlt698TimeTag());
}

void Dlt698ClientApdu::decode(const vector<BYTE> &res, size_t &pos)
{
    this->enumDecode(res, pos, sevType);
    body.reset(this->bodyInstance(sevType));
    body->decode(res, pos);
    this->baseDecode(res, pos, timeTagExist);
    if(timeTagExist) timeTag->decode(res, pos);
}

void Dlt698ClientApdu::encode(vector<BYTE> &res)
{
    this->enumEncode(res, sevType);
    body->encode(res);
    this->baseEncode(res, timeTagExist);
    if(timeTagExist) timeTag->encode(res);
}

eClientAPDU Dlt698ClientApdu::getSevType() const
{
    return sevType;
}

void Dlt698ClientApdu::setSevType(const eClientAPDU &value)
{
    body.reset(this->bodyInstance(value));
    sevType = value;
}


shared_ptr<Dlt698TimeTag> Dlt698ClientApdu::getTimeTag() const
{
    return timeTag;
}

void Dlt698ClientApdu::setTimeTag(const shared_ptr<Dlt698TimeTag> &value)
{
    timeTag = value;
}

bool_c Dlt698ClientApdu::getTimeTagExist() const
{
    return timeTagExist;
}

void Dlt698ClientApdu::setTimeTagExist(const bool_c &value)
{
    timeTagExist = value;
}

shared_ptr<Dlt698Proctol> Dlt698ClientApdu::getBody() const
{
    return body;
}

Dlt698Proctol *Dlt698ClientApdu::bodyInstance(eClientAPDU type)
{
    switch (type) {
    case _ConnectRequest:
        return new Dlt698ConnectRequest();
        break;
    case _ReleaseRequest:
        break;
    case _GetRequest:
        return new GetRequest();
        break;
    case _SetRequest:
        break;
    case _ActionRequest:
        break;
    case _ReportResponse:
        return new Dlt698ReportResponse();
        break;
    case _ProxyRequest:
        break;
    case _Error_Response1:
        break;
    }
    return new Dlt698Proctol();
}
