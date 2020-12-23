#ifndef REPORTNOTIFICATIONLISTBUILDER_H
#define REPORTNOTIFICATIONLISTBUILDER_H

#include "reportnotificationbuilder.h"
#include "server/get/dlt698getresponsenormallist.h"

namespace Dlt698 {

class ReportNotificationListBuilder : public ReportNotificationBuilder
{
public:
    ReportNotificationListBuilder();
    ReportNotificationListBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698GetResponseNormalList> notification() const;
    void setNotification(const shared_ptr<Dlt698GetResponseNormalList> &notification);

private:
    shared_ptr<Dlt698GetResponseNormalList> m_notification;
};

}

#endif // REPORTNOTIFICATIONLISTBUILDER_H
