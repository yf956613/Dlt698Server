#ifndef DLT698GETRESPONSENORMALLIST_H
#define DLT698GETRESPONSENORMALLIST_H

#include "datatype/row.h"
#include "server/resultnormal.h"
#include "common/dlt698piidacd.h"

using namespace Dlt698;

class Dlt698GetResponseNormalList : public Dlt698Proctol
{
public:
    Dlt698GetResponseNormalList();

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    shared_ptr<Dlt698PiidAcd> getPiid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &value);

    shared_ptr<Row<ResultNormal> > getResults() const;
    void setResults(const shared_ptr<Row<ResultNormal> > &value);

private:
    shared_ptr<Dlt698PiidAcd> piid;

    shared_ptr<Row<ResultNormal>> results;
};

#endif // DLT698GETRESPONSENORMALLIST_H
