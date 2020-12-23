#ifndef DLT698_RCSD_H
#define DLT698_RCSD_H

#include "csd.h"
#include "row.h"

namespace Dlt698 {

class Rcsd : public Dlt698Proctol
{
public:
    Rcsd();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    shared_ptr<Row<Csd> > getRcsd() const;
    void setRcsd(const shared_ptr<Row<Csd> > &value);

private:
    shared_ptr<Row<Csd> > rcsd;

};

}

#endif // Rcsd_H
