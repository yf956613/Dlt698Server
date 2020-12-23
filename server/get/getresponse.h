#ifndef DLT698_GETRESPONSE_H
#define DLT698_GETRESPONSE_H

#include "dlt698proctol.h"

namespace Dlt698 {

typedef enum _eGETResponse
{
    _GetResponseNormal=1,//读取一个对象属性的响应         	[1] ，
    _GetResponseNormalList,//读取若干个对象属性的响应       	[2]  ，
    _GetResponseRecord,//读取一个记录型对象属性的响应   	[3] ，
    _GetResponseRecordList,//读取若干个记录型对象属性的响应 	[4] ，
    _GetResponseNext,//分帧响应一个数据块                	[5]  ,
    _GetResponseMD5//读取一个对象属性的MD5值的响应      [6]

}eGetResponse;

class GetResponse : public Dlt698Proctol
{
public:
    GetResponse(eGetResponse type = _GetResponseNormal);

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    eGetResponse type() const;
    void setType(const eGetResponse &type);

    shared_ptr<Dlt698Proctol> body() const;
    Dlt698Proctol* bodyInstance(eGetResponse type);

private:
    eGetResponse m_type;

    shared_ptr<Dlt698Proctol> m_body;
};

}

#endif // GETRESPONSE_H
