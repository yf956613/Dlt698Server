#include "reportnotificationrecordlistbuilder.h"

using namespace Dlt698;

ReportNotificationRecordListBuilder::ReportNotificationRecordListBuilder()
{
    this->report()->setSevType(_ReportNotificationRecordList);
    m_records = dynamic_pointer_cast<Dlt698GetResponseRecordList>(this->report()->getBody());
}

ReportNotificationRecordListBuilder::ReportNotificationRecordListBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ReportNotificationBuilder(apdu)
{
    if(this->report())
    m_records = dynamic_pointer_cast<Dlt698GetResponseRecordList>(this->report()->getBody());
}

shared_ptr<Dlt698GetResponseRecordList> ReportNotificationRecordListBuilder::records() const
{
    return m_records;
}

void ReportNotificationRecordListBuilder::setRecords(const shared_ptr<Dlt698GetResponseRecordList> &records)
{
    m_records = records;
}


