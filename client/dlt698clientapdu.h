#ifndef DLT698CLIENTAPDU_H
#define DLT698CLIENTAPDU_H

#include "dlt698proctol.h"
#include "common/dlt698timetag.h"

using namespace Dlt698;

namespace Dlt698 {

typedef enum _eClientAPDU
{
    ///     建立应用连接请求
    _ConnectRequest = 2,
    ///     断开应用连接请求
    _ReleaseRequest = 3,
    ///     读取请求
    _GetRequest = 5,
    ///     设置请求
    _SetRequest = 6,
    ///     操作请求
    _ActionRequest = 7,
    ///     上报应答
    _ReportResponse = 8,
    ///     代理请求
    _ProxyRequest = 9,
    //      异常响应
    _Error_Response1=110

}eClientAPDU;

}

class Dlt698ClientApdu : public Dlt698Proctol
{
public:
    Dlt698ClientApdu(eClientAPDU type = _ConnectRequest, bool_c tagExist = false);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    eClientAPDU getSevType() const;
    void setSevType(const eClientAPDU &value);

    shared_ptr<Dlt698TimeTag> getTimeTag() const;
    void setTimeTag(const shared_ptr<Dlt698TimeTag> &value);

    bool_c getTimeTagExist() const;
    void setTimeTagExist(const bool_c &value);

    shared_ptr<Dlt698Proctol> getBody() const;
    Dlt698Proctol* bodyInstance(eClientAPDU type);

private:
    eClientAPDU sevType;

    shared_ptr<Dlt698Proctol> body;

    bool_c timeTagExist;

    shared_ptr<Dlt698TimeTag> timeTag;

};

#endif // DLT698CLIENTAPDU_H
