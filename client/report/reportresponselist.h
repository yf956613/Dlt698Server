#ifndef REPORTRESPONSELIST_H
#define REPORTRESPONSELIST_H

#include "common/dlt698piidacd.h"
#include "datatype/row.h"
#include "datatype/oad.h"

namespace Dlt698 {

class ReportResponseList : public Dlt698Proctol
{
public:
    ReportResponseList();

    shared_ptr<Row<Oad> > oads() const;
    void setOads(const shared_ptr<Row<Oad> > &oads);

    shared_ptr<Dlt698PiidAcd> piid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &piid);

private:
    shared_ptr<Dlt698PiidAcd> m_piid;
    shared_ptr<Row<Oad>> m_oads;

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;
};

}

#endif // REPORTRESPONSELIST_H
