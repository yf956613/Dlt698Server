#include "dlt698followreport.h"
#include "resultnormal.h"
#include "resultrecord.h"

Dlt698FollowReport::Dlt698FollowReport(reportType t)
    : type(t)
{
    body.reset(this->bodyInstance(type));
}

void Dlt698FollowReport::decode(const vector<BYTE> &res, size_t &pos)
{
    this->enumDecode(res, pos, type);
    body.reset(this->bodyInstance(type));
    body->decode(res, pos);
}

void Dlt698FollowReport::encode(vector<BYTE> &res)
{
    this->enumEncode(res, type);
    body->encode(res);
}

Dlt698FollowReport::reportType Dlt698FollowReport::getType() const
{
    return type;
}

void Dlt698FollowReport::setType(const reportType &value)
{
    type = value;
    body.reset(this->bodyInstance(value));
}

shared_ptr<Dlt698Proctol> Dlt698FollowReport::getBody() const
{
    return body;
}

Dlt698Proctol *Dlt698FollowReport::bodyInstance(Dlt698FollowReport::reportType value)
{
    switch(value) {
    case _resultNormal:
        return new Dlt698::ResultNormal();
        break;
    case _resultRecord:
        return new Dlt698::ResultRecord();
        break;
    }
    return new Dlt698Proctol();
}
