#ifndef DLT698FOLLOWREPORT_H
#define DLT698FOLLOWREPORT_H

#include "dlt698proctol.h"

class Dlt698FollowReport : public Dlt698Proctol
{
public:
    typedef enum _eReportType{
        _resultNormal = 1,
        _resultRecord = 2
    }reportType;

    Dlt698FollowReport(reportType t = _resultNormal);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    reportType getType() const;
    void setType(const reportType &value);

    shared_ptr<Dlt698Proctol> getBody() const;
    Dlt698Proctol* bodyInstance(reportType value);

private:
    reportType type;

    shared_ptr<Dlt698Proctol> body;
};

#endif // DLT698FOLLOWREPORT_H
