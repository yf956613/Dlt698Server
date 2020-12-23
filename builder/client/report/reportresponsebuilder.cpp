#include "reportresponsebuilder.h"

ReportResponseBuilder::ReportResponseBuilder()
{
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setPRM(_SevStart);

    this->client()->setSevType(_ReportResponse);
    m_report = dynamic_pointer_cast<Dlt698ReportResponse>(this->client()->getBody());
}

ReportResponseBuilder::ReportResponseBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ClientBuilder(apdu)
{
    if(this->client())
    m_report = dynamic_pointer_cast<Dlt698ReportResponse>(this->client()->getBody());
}

shared_ptr<Dlt698ReportResponse> ReportResponseBuilder::report() const
{
    return m_report;
}

void ReportResponseBuilder::setReport(const shared_ptr<Dlt698ReportResponse> &report)
{
    m_report = report;
}
