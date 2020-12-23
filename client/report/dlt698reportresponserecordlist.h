#ifndef DLT698REPORTRESPONSERECORDLIST_H
#define DLT698REPORTRESPONSERECORDLIST_H

#include "common/dlt698piid.h"
#include "datatype/oad.h"
#include "datatype/row.h"

using namespace Dlt698;

class Dlt698ReportResponseRecordList : public Dlt698Proctol
{
public:
    Dlt698ReportResponseRecordList();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    shared_ptr<Dlt698Piid> getPiid() const;
    void setPiid(const shared_ptr<Dlt698Piid> &value);

    shared_ptr<Row<Oad> > getOads() const;
    void setOads(const shared_ptr<Row<Oad> > &value);

private:
    shared_ptr<Dlt698Piid> piid;
    shared_ptr<Row<Oad>> oads;
};

#endif // DLT698REPORTRESPONSERECORDLIST_H
