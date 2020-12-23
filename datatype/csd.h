#ifndef DLT698_CSD_H
#define DLT698_CSD_H

#include "data.h"

namespace Dlt698 {

enum eCSD
{
    _OAD=0,
    _ROAD=1
};

class Csd : public Data
{
public:
    Csd(eCSD csd = _OAD);
\
    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    eCSD getECsd() const;
    void setECsd(const eCSD &value);

    shared_ptr<Dlt698Proctol> getUscd() const;
    Dlt698Proctol* bodyInstance(eCSD type);

private:
    eCSD eCsd;

    shared_ptr<Dlt698Proctol> uscd;
};

}

#endif // CSD_H
