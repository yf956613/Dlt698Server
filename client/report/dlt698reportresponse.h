#ifndef DLT698REPORTRESPONSE_H
#define DLT698REPORTRESPONSE_H

#include "dlt698proctol.h"

namespace Dlt698 {

typedef enum _eREPORTResponse
{
    _ReportResponseList=1,
    _ReportResponseRecordList,
    _ReportResponseTransData
}eReportResponse;

}

using namespace Dlt698;

class Dlt698ReportResponse : public Dlt698Proctol
{
public:
    Dlt698ReportResponse(eReportResponse type = _ReportResponseList);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    eReportResponse getSevType() const;
    void setSevType(const eReportResponse &value);

    shared_ptr<Dlt698Proctol> getBody() const;
    Dlt698Proctol* bodyInstance(eReportResponse type) const;

private:
    eReportResponse sevType;

    shared_ptr<Dlt698Proctol> body;
};

#endif // DLT698REPORTRESPONSE_H
