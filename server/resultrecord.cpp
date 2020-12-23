#include "resultrecord.h"
#include "dlt698data.h"
#include "datatype/row.h"
#include "common/dar.h"

using namespace Dlt698;

ResultRecord::ResultRecord(eResponseData type)
    : choiceRespDat(type)
{
    oad.reset(new Oad());
    rcsd.reset(new Rcsd());
    data.reset(this->bodyInstance(type));
}

shared_ptr<Dlt698Proctol> ResultRecord::getData() const
{
    return data;
}

Dlt698Proctol *Dlt698::ResultRecord::bodyInstance(Dlt698::eResponseData type)
{
    switch(type) {
    case _DA:
        return new DAR();
        break;
    case _DATA:
        return new Row<Dlt698Data>();
        break;
    }
    return new Dlt698Proctol();
}

eResponseData ResultRecord::getChoiceRespDat() const
{
    return choiceRespDat;
}

void ResultRecord::setChoiceRespDat(const eResponseData &value)
{
    choiceRespDat = value;
    data.reset(this->bodyInstance(value));
}

shared_ptr<Rcsd> ResultRecord::getRcsd() const
{
    return rcsd;
}

void ResultRecord::setRcsd(const shared_ptr<Rcsd> &value)
{
    rcsd = value;
}

void ResultRecord::decode(const vector<BYTE> &res, size_t &pos)
{
    oad->decode(res, pos);
    rcsd->decode(res, pos);
    choiceRespDat = (eResponseData)res[pos ++];
    data.reset(this->bodyInstance(choiceRespDat));
    data->decode(res, pos);
}

void ResultRecord::encode(vector<BYTE> &res)
{
    oad->encode(res);
    rcsd->encode(res);
    this->baseEncode(res, (BYTE)choiceRespDat);
    data->encode(res);
}

shared_ptr<Oad> ResultRecord::getOad() const
{
    return oad;
}

void ResultRecord::setOad(const shared_ptr<Oad> &value)
{
    oad = value;
}
