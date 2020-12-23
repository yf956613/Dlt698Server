#ifndef DLT698GETRESPONSERECORD_H
#define DLT698GETRESPONSERECORD_H

#include "server/resultrecord.h"
#include "common/dlt698piidacd.h"

using namespace Dlt698;

class Dlt698GetResponseRecord : public Dlt698Proctol
{
public:
    Dlt698GetResponseRecord();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    shared_ptr<Dlt698PiidAcd> getPiid() const;
    void setPiid(const shared_ptr<Dlt698PiidAcd> &value);

    shared_ptr<ResultRecord> getResult() const;
    void setResult(const shared_ptr<ResultRecord> &value);

private:
    shared_ptr<Dlt698PiidAcd> piid;
    shared_ptr<ResultRecord> result;
};

#endif // DLT698GETRESPONSERECORD_H
