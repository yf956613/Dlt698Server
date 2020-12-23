#include "servicereportnotificationnormallist.h"
#include "dlt698servicefactory.h"
#include "server/report/dlt698reportnotification.h"
#include "server/dlt698serverapdu.h"
#include "server/get/dlt698getresponsenormallist.h"
#include <QDebug>

using namespace Dlt698;

ServiceReportNotificationNormalList::ServiceReportNotificationNormalList()
{
    WORD type = this->getServiceType(_ReportNotification, _ReportNotificationList);
    Dlt698ServiceFactory::instance()->setService(type, this);
}

void ServiceReportNotificationNormalList::doService(ServiceRequest &request, ServiceResponse &response)
{
    qDebug() << "ReportNotificationList: 88 01";

    size_t pos = 0;
    Dlt698ServerApdu server;
    server.decode(request.getApdu()->getByASDU(), pos);

    qDebug() << QString::fromStdString(server.toHexString());
}
