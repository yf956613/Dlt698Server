#ifndef REPORTNOTIFICATIONRECORDLISTBUILDER_H
#define REPORTNOTIFICATIONRECORDLISTBUILDER_H

#include "reportnotificationbuilder.h"
#include "server/get/dlt698getresponserecordlist.h"

namespace Dlt698 {

class ReportNotificationRecordListBuilder : public ReportNotificationBuilder
{
public:
    ReportNotificationRecordListBuilder();
    ReportNotificationRecordListBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698GetResponseRecordList> records() const;
    void setRecords(const shared_ptr<Dlt698GetResponseRecordList> &records);

private:
    shared_ptr<Dlt698GetResponseRecordList> m_records;
};


}

#endif // REPORTNOTIFICATIONRECORDLISTBUILDER_H
