#ifndef REPORTRESPONSELISTBUILDER_H
#define REPORTRESPONSELISTBUILDER_H

#include "reportresponsebuilder.h"
#include "client/report/reportresponselist.h"

namespace Dlt698 {

class ReportResponseListBuilder : public ReportResponseBuilder
{
public:
    ReportResponseListBuilder();
    ReportResponseListBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<ReportResponseList> response() const;
    void setResponse(const shared_ptr<ReportResponseList> &response);

private:
    shared_ptr<ReportResponseList> m_response;
};

}

#endif // REPORTRESPONSELISTBUILDER_H
