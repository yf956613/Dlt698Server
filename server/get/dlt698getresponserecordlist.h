#ifndef DLT698GETRESPONSERECORDLIST_H
#define DLT698GETRESPONSERECORDLIST_H

#include "datatype/row.h"
#include "server/resultrecord.h"
#include "common/dlt698piidacd.h"

using namespace Dlt698;

class Dlt698GetResponseRecordList : public Dlt698Proctol
{
public:
    Dlt698GetResponseRecordList();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    shared_ptr<Dlt698PiidAcd> getPiid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &value);

    shared_ptr<Row<ResultRecord> > getResults() const;
    void setResults(const shared_ptr<Row<ResultRecord> > &value);

private:
    shared_ptr<Dlt698PiidAcd> piid;

    shared_ptr<Row<ResultRecord>> results;
};

#endif // DLT698GETRESPONSERECORDLIST_H
