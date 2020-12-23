#ifndef DLT698REPORTNOTIFICATION_H
#define DLT698REPORTNOTIFICATION_H

#include "dlt698proctol.h"

namespace Dlt698 {

typedef enum _eREPORTNotification
{
    _ReportNotificationList=1,//上报若干个对象属性         [1] ，
    _ReportNotificationRecordList,//上报若干个记录型对象属性   [2] ，
    _ReportNotificationTransData//上报透明数据               [3]

}eReportNotification;

}

using namespace Dlt698;

class Dlt698ReportNotification : public Dlt698Proctol
{
public:
    Dlt698ReportNotification(eReportNotification type = _ReportNotificationRecordList);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    eReportNotification getSevType() const;
    void setSevType(const eReportNotification &value);


    shared_ptr<Dlt698Proctol> getBody() const;
    Dlt698Proctol* bodyInstance(eReportNotification type);

private:
    eReportNotification sevType;

    shared_ptr<Dlt698Proctol> body;
};

#endif // DLT698REPORTNOTIFICATION_H
