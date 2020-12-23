#include "dlt698reportnotification.h"
#include "server/get/dlt698getresponsenormallist.h"
#include "server/get/dlt698getresponserecordlist.h"

using namespace Dlt698;

Dlt698ReportNotification::Dlt698ReportNotification(eReportNotification type)
    : sevType(type)
{
    body.reset(this->bodyInstance(sevType));
}

void Dlt698ReportNotification::decode(const vector<BYTE> &res, size_t &pos)
{
    this->enumDecode(res, pos, sevType);
    body.reset(this->bodyInstance(sevType));
    body->decode(res, pos);
}

void Dlt698ReportNotification::encode(vector<BYTE> &res)
{
    this->enumEncode(res, sevType);
    body->encode(res);
}

eReportNotification Dlt698ReportNotification::getSevType() const
{
    return sevType;
}

void Dlt698ReportNotification::setSevType(const eReportNotification &value)
{
    sevType = value;
    body.reset(this->bodyInstance(sevType));
}

shared_ptr<Dlt698Proctol> Dlt698ReportNotification::getBody() const
{
    return body;
}

Dlt698Proctol *Dlt698ReportNotification::bodyInstance(eReportNotification type)
{
    switch(type) {
    case _ReportNotificationList:
        return new Dlt698GetResponseNormalList();
        break;//上报若干个对象属性         [1] ，
    case _ReportNotificationRecordList:
        return new Dlt698GetResponseRecordList();
        break;//上报若干个记录型对象属性   [2] ，
    case _ReportNotificationTransData:
        break;//上报透明数据               [3]
    }
    return new Dlt698Proctol();
}

