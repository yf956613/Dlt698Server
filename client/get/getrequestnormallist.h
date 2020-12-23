#ifndef GETREQUESTNORMALLIST_H
#define GETREQUESTNORMALLIST_H

#include "datatype/row.h"
#include "common/dlt698piid.h"
#include "datatype/oad.h"

namespace Dlt698 {

class GetRequestNormalList : public Dlt698Proctol
{
public:
    GetRequestNormalList();

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    shared_ptr<Dlt698Piid> piid() const;
    void setPiid(const shared_ptr<Dlt698Piid> &piid);

    shared_ptr<Row<Oad> > oads() const;
    void setOads(const shared_ptr<Row<Oad> > &oads);

private:
    shared_ptr<Dlt698Piid> m_piid;
    shared_ptr<Row<Oad>> m_oads;
};

}



#endif // GETREQUESTNORMALLIST_H
