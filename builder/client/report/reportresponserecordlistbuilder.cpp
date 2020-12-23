#include "reportresponserecordlistbuilder.h"

using namespace Dlt698;

ReportResponseRecordListBuilder::ReportResponseRecordListBuilder()
{
    this->report()->setSevType(_ReportResponseRecordList);
    m_response = dynamic_pointer_cast<Dlt698ReportResponseRecordList>(this->report()->getBody());
}

ReportResponseRecordListBuilder::ReportResponseRecordListBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ReportResponseBuilder(apdu)
{
    if(this->report())
    m_response = dynamic_pointer_cast<Dlt698ReportResponseRecordList>(this->report()->getBody());
}

shared_ptr<Dlt698ReportResponseRecordList> ReportResponseRecordListBuilder::response() const
{
    return m_response;
}

void ReportResponseRecordListBuilder::setResponse(const shared_ptr<Dlt698ReportResponseRecordList> &response)
{
    m_response = response;
}
