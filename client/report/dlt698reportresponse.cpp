#include "dlt698reportresponse.h"
#include "dlt698reportresponserecordlist.h"
#include "reportresponselist.h"

Dlt698ReportResponse::Dlt698ReportResponse(eReportResponse type)
    : sevType(type)
{
    body.reset(this->bodyInstance(type));
}

void Dlt698ReportResponse::decode(const vector<BYTE> &res, size_t &pos)
{
    this->enumDecode(res, pos, sevType);
    body.reset(this->bodyInstance(sevType));
    body->decode(res, pos);
}

void Dlt698ReportResponse::encode(vector<BYTE> &res)
{
    this->enumEncode(res, sevType);
    body->encode(res);
}

eReportResponse Dlt698ReportResponse::getSevType() const
{
    return sevType;
}

void Dlt698ReportResponse::setSevType(const eReportResponse &value)
{
    sevType = value;
    body.reset(this->bodyInstance(value));
}

shared_ptr<Dlt698Proctol> Dlt698ReportResponse::getBody() const
{
    return body;
}

Dlt698Proctol *Dlt698ReportResponse::bodyInstance(eReportResponse type) const
{
    switch (type) {
    case _ReportResponseList:
        return new ReportResponseList();
        break;
    case _ReportResponseRecordList:
        return new Dlt698ReportResponseRecordList();
        break;
    case _ReportResponseTransData:
        break;
    }
    return new Dlt698Proctol();
}
