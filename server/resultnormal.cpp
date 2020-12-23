#include "resultnormal.h"
#include "common/dar.h"
#include "dlt698data.h"

using namespace Dlt698;

ResultNormal::ResultNormal(eGetResult type)
 : resultType(type)
{
    oad.reset(new Oad());
    result.reset(this->bodyInstance(type));
}

shared_ptr<Oad> ResultNormal::getOad() const
{
    return oad;
}

void ResultNormal::setOad(const shared_ptr<Oad> &value)
{
    oad = value;
}

eGetResult ResultNormal::getResultType() const
{
    return resultType;
}

void ResultNormal::setResultType(const eGetResult &value)
{
    resultType = value;
    result.reset(this->bodyInstance(value));
}

shared_ptr<Dlt698Proctol> ResultNormal::getResult() const
{
    return result;
}

Dlt698Proctol *ResultNormal::bodyInstance(eGetResult type)
{
    switch(type) {
    case _DAR:
        return new DAR();
        break;
    case _Data:
        return new Dlt698Data();
        break;
    }
}

void ResultNormal::decode(const vector<BYTE> &res, size_t &pos)
{
    oad->decode(res, pos);
    resultType = (eGetResult)res[pos ++];
    result.reset(this->bodyInstance(resultType));
    result->decode(res, pos);
}

void ResultNormal::encode(vector<BYTE> &res)
{
    this->oad->encode(res);
    this->baseEncode(res, (BYTE)this->resultType);
    result->encode(res);
}
