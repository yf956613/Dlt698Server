#include "reportnotificationlistbuilder.h"

using namespace Dlt698;

ReportNotificationListBuilder::ReportNotificationListBuilder()
{
    this->report()->setSevType(_ReportNotificationList);
    m_notification = dynamic_pointer_cast<Dlt698GetResponseNormalList>(this->report()->getBody());
}

ReportNotificationListBuilder::ReportNotificationListBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ReportNotificationBuilder(apdu)
{
    if(this->report())
    m_notification = dynamic_pointer_cast<Dlt698GetResponseNormalList>(this->report()->getBody());
}

shared_ptr<Dlt698GetResponseNormalList> ReportNotificationListBuilder::notification() const
{
    return m_notification;
}

void ReportNotificationListBuilder::setNotification(const shared_ptr<Dlt698GetResponseNormalList> &notification)
{
    m_notification = notification;
}
