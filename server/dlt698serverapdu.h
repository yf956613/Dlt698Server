#ifndef DLT698SERVERAPDU_H
#define DLT698SERVERAPDU_H

#include "common/dlt698timetag.h"
#include "dlt698followreport.h"

namespace Dlt698 {

typedef enum _eServerAPDU
{
    ///     建立应用连接响应
    _ConnectResponse = 130,
    ///     断开应用连接响应
    _ReleaseResponse = 131,
    ///     断开应用连接通知
    _ReleaseNotification = 132,
    ///     读取响应
    _GetResponse = 133,
    ///     设置响应
    _SetResponse = 134,
    ///     操作响应
    _ActionResponse = 135,
    ///     上报通知
    _ReportNotification = 136,
    ///     代理响应
    _ProxyResponse = 137,
    //      异常响应
    _Error_Response2=238

}eServerAPDU;

}

using namespace Dlt698;

class Dlt698ServerApdu : public Dlt698Proctol
{
public:
    Dlt698ServerApdu(eServerAPDU type = _ReportNotification);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    eServerAPDU getSevType() const;
    void setSevType(const eServerAPDU &value);

    bool_c getFollowReportExist() const;
    void setFollowReportExist(const bool_c &value);

    shared_ptr<Dlt698FollowReport> getFollowReport() const;
    void setFollowReport(const shared_ptr<Dlt698FollowReport> &value);

    bool_c getTimeTagExist() const;
    void setTimeTagExist(const bool_c &value);

    shared_ptr<Dlt698TimeTag> getTimeTag() const;
    void setTimeTag(const shared_ptr<Dlt698TimeTag> &value);

    shared_ptr<Dlt698Proctol> getBody() const;
    Dlt698Proctol* bodyInstance(eServerAPDU type);

private:
    eServerAPDU sevType;

    shared_ptr<Dlt698Proctol> body;

    bool_c followReportExist;

    shared_ptr<Dlt698FollowReport> followReport;

    bool_c timeTagExist;

    shared_ptr<Dlt698TimeTag> timeTag;
};

#endif // DLT698SERVERAPDU_H
