#ifndef GETREQUESTNORMAL_H
#define GETREQUESTNORMAL_H

#include "datatype/oad.h"
#include "common/dlt698piid.h"

namespace Dlt698 {

class GetRequestNormal : public Dlt698Proctol
{
public:
    GetRequestNormal();

    shared_ptr<Dlt698Piid> piid() const;
    void setPiid(const shared_ptr<Dlt698Piid> &piid);

    shared_ptr<Oad> oad() const;
    void setOad(const shared_ptr<Oad> &oad);

private:
    shared_ptr<Dlt698Piid> m_piid;

    shared_ptr<Oad> m_oad;

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;
};

}

#endif
