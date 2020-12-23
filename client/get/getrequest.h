#ifndef DLT698_GETREQUEST_H
#define DLT698_GETREQUEST_H

#include "dlt698proctol.h"

namespace Dlt698 {

typedef enum _eGetRequest
{
    _GetRequestNormal=1, //读取一个对象属性请求[1]
    _GetRequestNormalList, //读取若干个对象属性请求[2]
    _GetRequestRecord, //读取一个记录型对象属性请求[3]
    _GetRequestRecordList, //读取若干个记录型对象属性请求[4]
    _GetRequestNext,//读取分帧响应的下一个数据块请求[5]
    _GetRequestMD5//读取一个对象属性的MD5值[6]

}eGetRequest;

class GetRequest : public Dlt698Proctol
{
public:
    GetRequest(eGetRequest type = _GetRequestNormal);

    eGetRequest type() const;
    void setType(const eGetRequest &type);

    shared_ptr<Dlt698Proctol> body() const;
    Dlt698Proctol*  bodyInstance(eGetRequest type) const;
private:
    eGetRequest m_type;

    shared_ptr<Dlt698Proctol> m_body;

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;
};

}

#endif // GETREQUEST_H
