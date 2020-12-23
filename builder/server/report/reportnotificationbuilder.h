#ifndef REPORTNOTIFICATIONBUILDER_H
#define REPORTNOTIFICATIONBUILDER_H

#include "builder/server/serverbuilder.h"
#include "server/report/dlt698reportnotification.h"

namespace Dlt698 {

class ReportNotificationBuilder : public ServerBuilder
{
public:
    ReportNotificationBuilder();
    ReportNotificationBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698ReportNotification> report() const;
    void setReport(const shared_ptr<Dlt698ReportNotification> &report);

private:
    shared_ptr<Dlt698ReportNotification> m_report;
};

}

#endif
