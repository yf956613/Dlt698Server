#ifndef REPORTRESPONSERECORDLISTBUILDER_H
#define REPORTRESPONSERECORDLISTBUILDER_H

#include "reportresponsebuilder.h"
#include "client/report/dlt698reportresponserecordlist.h"

namespace Dlt698 {

class ReportResponseRecordListBuilder : public ReportResponseBuilder
{
public:
    ReportResponseRecordListBuilder();
    ReportResponseRecordListBuilder(shared_ptr<Dlt698Apdu> apdu = nullptr);

    shared_ptr<Dlt698ReportResponseRecordList> response() const;
    void setResponse(const shared_ptr<Dlt698ReportResponseRecordList> &response);

private:
    shared_ptr<Dlt698ReportResponseRecordList> m_response;
};

}



#endif // REPORTRESPONSERECORDLISTBUILDER_H
