#include "reportresponselistbuilder.h"

ReportResponseListBuilder::ReportResponseListBuilder()
{
    this->report()->setSevType(_ReportResponseList);
    m_response = dynamic_pointer_cast<ReportResponseList>(this->report()->getBody());
}

ReportResponseListBuilder::ReportResponseListBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ReportResponseBuilder(apdu)
{
    if(this->report())
    m_response = dynamic_pointer_cast<ReportResponseList>(this->report()->getBody());
}

shared_ptr<ReportResponseList> ReportResponseListBuilder::response() const
{
    return m_response;
}

void ReportResponseListBuilder::setResponse(const shared_ptr<ReportResponseList> &response)
{
    m_response = response;
}
