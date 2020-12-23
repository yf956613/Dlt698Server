#include "rcsd.h"

using namespace Dlt698;

Rcsd::Rcsd()
{
    this->rcsd.reset(new Row<Csd>());
}

void Rcsd::decode(const vector<BYTE> &res, size_t &pos)
{
    this->rcsd->decode(res, pos);
}

void Rcsd::encode(vector<BYTE> &res)
{
    this->rcsd->encode(res);
}

shared_ptr<Row<Csd> > Rcsd::getRcsd() const
{
    return rcsd;
}

void Rcsd::setRcsd(const shared_ptr<Row<Csd> > &value)
{
    rcsd = value;
}

