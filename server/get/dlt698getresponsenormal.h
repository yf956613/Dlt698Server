#ifndef DLT698GETRESPONSENORMAL_H
#define DLT698GETRESPONSENORMAL_H

#include "common/dlt698piidacd.h"
#include "server/resultnormal.h"
#include <QDebug>

class Dlt698GetResponseNormal : public Dlt698Proctol
{
public:
    Dlt698GetResponseNormal();

    shared_ptr<Dlt698PiidAcd> getPiid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &value);

    shared_ptr<Dlt698::ResultNormal> getResult() const;
    void setResult(const shared_ptr<Dlt698::ResultNormal> &value);

private:
    shared_ptr<Dlt698PiidAcd> piid;
    shared_ptr<Dlt698::ResultNormal> result;

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

};

#endif // DLT698GETRESPONSENORMAL_H
