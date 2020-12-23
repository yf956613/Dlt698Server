#include "reportnotificationbuilder.h"

using namespace Dlt698;


ReportNotificationBuilder::ReportNotificationBuilder()
{
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setPRM(_SevStart);

    this->server()->setSevType(_ReportNotification);
    m_report = dynamic_pointer_cast<Dlt698ReportNotification>(this->server()->getBody());
}

ReportNotificationBuilder::ReportNotificationBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ServerBuilder(apdu)
{
    if(this->server())
    m_report = dynamic_pointer_cast<Dlt698ReportNotification>(this->server()->getBody());
}

shared_ptr<Dlt698ReportNotification> ReportNotificationBuilder::report() const
{
    return m_report;
}

void ReportNotificationBuilder::setReport(const shared_ptr<Dlt698ReportNotification> &report)
{
    m_report = report;
}
