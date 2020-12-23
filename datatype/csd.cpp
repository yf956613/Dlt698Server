#include "csd.h"
#include "oad.h"
#include "road.h"

using namespace Dlt698;

Csd::Csd(eCSD csd) : eCsd(csd)
{
    uscd.reset(this->bodyInstance(csd));
}

void Csd::decode(const vector<BYTE> &res, size_t &pos)
{
    eCsd = (eCSD)res[pos ++];
    uscd.reset(this->bodyInstance(eCsd));
    uscd->decode(res, pos);
}

void Csd::encode(vector<BYTE> &res)
{
    this->baseEncode(res, (BYTE)this->eCsd);
    uscd->encode(res);
}

eCSD Csd::getECsd() const
{
    return eCsd;
}

void Csd::setECsd(const eCSD &value)
{
    eCsd = value;
    uscd.reset(this->bodyInstance(eCsd));
}

shared_ptr<Dlt698Proctol> Csd::getUscd() const
{
    return uscd;
}

Dlt698Proctol *Csd::bodyInstance(eCSD type)
{
    switch (type) {
    case _OAD:
        return new Oad();
        break;
    case _ROAD:
        return new Road();
        break;
    }
    return new Dlt698Proctol();
}
