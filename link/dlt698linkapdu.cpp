#include "dlt698linkapdu.h"
#include "dlt698linkrequest.h"
#include "dlt698linkresponse.h"

Dlt698LinkApdu::Dlt698LinkApdu(eLinkAPDU type)
    : sevType(type)
{
    body.reset(this->bodyInstance(sevType));
}

void Dlt698LinkApdu::decode(const vector<BYTE> &res, size_t &pos)
{
    this->enumDecode(res, pos, sevType);
    body.reset(this->bodyInstance(sevType));
    body->decode(res, pos);
}

void Dlt698LinkApdu::encode(vector<BYTE> &res)
{
    this->enumEncode(res, sevType);
    body->encode(res);
}

eLinkAPDU Dlt698LinkApdu::getSevType() const
{
    return sevType;
}

void Dlt698LinkApdu::setSevType(const eLinkAPDU &value)
{
    sevType = value;
    body.reset(this->bodyInstance(sevType));
}

shared_ptr<Dlt698Proctol> Dlt698LinkApdu::getBody() const
{
    return body;
}

Dlt698Proctol *Dlt698LinkApdu::bodyInstance(eLinkAPDU type)
{
    switch (type) {
    case _LinkRequest:
        return new Dlt698LinkRequest();
        break;
    case _LinkResponse:
        return new Dlt698LinkResponse();
        break;
    }
    return new Dlt698Proctol();
}
