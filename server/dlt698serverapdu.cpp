#include "dlt698serverapdu.h"
#include "connect/dlt698connectresponse.h"
#include "get/getresponse.h"
#include "report/dlt698reportnotification.h"

Dlt698ServerApdu::Dlt698ServerApdu(eServerAPDU type)
    : sevType(type), timeTagExist(false), followReportExist(false)
{
    timeTag.reset(new Dlt698TimeTag());
    body.reset(this->bodyInstance(sevType));
    followReport.reset(new Dlt698FollowReport());
}

void Dlt698ServerApdu::decode(const vector<BYTE> &res, size_t &pos)
{
    this->enumDecode(res, pos, sevType);
    body.reset(this->bodyInstance(sevType));
    body->decode(res, pos);
    this->baseDecode(res, pos, followReportExist);
    if(followReportExist) followReport->decode(res, pos);
    this->baseDecode(res, pos, timeTagExist);
    if(timeTagExist) timeTag->decode(res, pos);
}

void Dlt698ServerApdu::encode(vector<BYTE> &res)
{
    this->enumEncode(res, sevType);
    body->encode(res);
    this->baseEncode(res, followReportExist);
    if(followReportExist) followReport->encode(res);
    this->baseEncode(res, timeTagExist);
    if(timeTagExist) timeTag->encode(res);
}

eServerAPDU Dlt698ServerApdu::getSevType() const
{
    return sevType;
}

void Dlt698ServerApdu::setSevType(const eServerAPDU &value)
{
    sevType = value;
}

bool_c Dlt698ServerApdu::getFollowReportExist() const
{
    return followReportExist;
}

void Dlt698ServerApdu::setFollowReportExist(const bool_c &value)
{
    followReportExist = value;
}

shared_ptr<Dlt698FollowReport> Dlt698ServerApdu::getFollowReport() const
{
    return followReport;
}

void Dlt698ServerApdu::setFollowReport(const shared_ptr<Dlt698FollowReport> &value)
{
    followReport = value;
}

bool_c Dlt698ServerApdu::getTimeTagExist() const
{
    return timeTagExist;
}

void Dlt698ServerApdu::setTimeTagExist(const bool_c &value)
{
    timeTagExist = value;
}

shared_ptr<Dlt698TimeTag> Dlt698ServerApdu::getTimeTag() const
{
    return timeTag;
}

void Dlt698ServerApdu::setTimeTag(const shared_ptr<Dlt698TimeTag> &value)
{
    timeTag = value;
}

shared_ptr<Dlt698Proctol> Dlt698ServerApdu::getBody() const
{
    return body;
}

Dlt698Proctol *Dlt698ServerApdu::bodyInstance(eServerAPDU type)
{
    switch(type) {
    case _ConnectResponse:
        return new Dlt698ConnectResponse();
        break;
    ///     断开应用连接响应
    case _ReleaseResponse:
        break;
    ///     断开应用连接通知
    case _ReleaseNotification:
        break;
    ///     读取响应
    case _GetResponse:
        return new GetResponse();
        break;
    ///     设置响应
    case _SetResponse:
        break;
    ///     操作响应
    case _ActionResponse:
        break;
    ///     上报通知
    case _ReportNotification:
        return new Dlt698ReportNotification();
        break;
    ///     代理响应
    case _ProxyResponse:
        break;
    //      异常响应
    case _Error_Response2:
        break;
    }
    return new Dlt698Proctol();
}
