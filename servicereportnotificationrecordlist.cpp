#include "servicereportnotificationrecordlist.h"
#include "dlt698servicefactory.h"
#include "server/report/dlt698reportnotification.h"
#include "server/dlt698serverapdu.h"
#include "server/get/dlt698getresponserecordlist.h"
#include <QDebug>

using namespace Dlt698;

ServiceReportNotificationRecordList::ServiceReportNotificationRecordList()
{
    WORD type = this->getServiceType(_ReportNotification, _ReportNotificationRecordList);
    Dlt698ServiceFactory::instance()->setService(type, this);
}

void ServiceReportNotificationRecordList::doService(Dlt698::ServiceRequest &request, Dlt698::ServiceResponse &response)
{
    qDebug() << "ReportNotificationList: 88 02";

    size_t pos = 0;
    Dlt698ServerApdu server;
    server.decode(request.getApdu()->getByASDU(), pos);

//    Dlt698ReportNotification report;
//    pos = 0;
//    report.decode(server.getBody(), pos);

//    shared_ptr<Dlt698GetResponseRecordList> res(new Dlt698GetResponseRecordList());
//    pos = 0;
//    res->decode(report.getBody(), pos);
    qDebug() << QString::fromStdString(server.toString());
}
