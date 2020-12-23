#ifndef REPORTRESPONSEBUILDER_H
#define REPORTRESPONSEBUILDER_H

#include "client/report/dlt698reportresponse.h"
#include "builder/client/clientbuilder.h"

namespace Dlt698 {

class ReportResponseBuilder : public ClientBuilder
{
public:
    ReportResponseBuilder();
    ReportResponseBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698ReportResponse> report() const;
    void setReport(const shared_ptr<Dlt698ReportResponse> &report);

private:
    shared_ptr<Dlt698ReportResponse> m_report;
};

}

#endif
