#include "getresponse.h"
#include "dlt698getresponsenormal.h"
#include "dlt698getresponsenormallist.h"
#include "dlt698getresponserecord.h"
#include "dlt698getresponserecordlist.h"

using namespace Dlt698;

GetResponse::GetResponse(eGetResponse type)
    : m_type(type)
{
    m_body.reset(this->bodyInstance(m_type));
}

void GetResponse::decode(const vector<BYTE> &res, size_t &pos)
{
    this->enumDecode(res, pos, m_type);
    m_body.reset(this->bodyInstance(m_type));
    m_body->decode(res, pos);
}

void GetResponse::encode(vector<BYTE> &res)
{
    this->enumEncode(res, m_type);
    m_body->encode(res);
}

eGetResponse GetResponse::type() const
{
    return m_type;
}

void GetResponse::setType(const eGetResponse &type)
{
    m_type = type;
    m_body.reset(this->bodyInstance(type));
}

shared_ptr<Dlt698Proctol> GetResponse::body() const
{
    return m_body;
}

Dlt698Proctol *GetResponse::bodyInstance(eGetResponse type)
{
    switch(type) {
    case _GetResponseNormal:
        return new Dlt698GetResponseNormal();
        break;//读取一个对象属性的响应         	[1] ，
    case _GetResponseNormalList:
        return new Dlt698GetResponseNormalList();
        break;//读取若干个对象属性的响应       	[2]  ，
    case _GetResponseRecord:
        return new Dlt698GetResponseRecord();
        break;//读取一个记录型对象属性的响应   	[3] ，
    case _GetResponseRecordList:
        return new Dlt698GetResponseRecordList();
        break;//读取若干个记录型对象属性的响应 	[4] ，
    case _GetResponseNext:
        break;//分帧响应一个数据块                	[5]  ,
    case _GetResponseMD5:
        break;//读取一个对象属性的MD5值的响应      [6]
    }
    return new Dlt698Proctol();
}
