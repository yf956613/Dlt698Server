#ifndef RESULTNORMAL_H
#define RESULTNORMAL_H

#include "datatype/oad.h"
#include "dlt698proctol.h"

namespace Dlt698 {

enum eGetResult
{
    _DAR=0,
    _Data=1
};

class ResultNormal : public Dlt698Proctol
{
public:
    ResultNormal(eGetResult type = _Data);

    shared_ptr<Oad> getOad() const;
    void setOad(const shared_ptr<Oad> &value);

    eGetResult getResultType() const;
    void setResultType(const eGetResult &value);

    shared_ptr<Dlt698Proctol> getResult() const;
    Dlt698Proctol* bodyInstance(eGetResult type);

private:
    shared_ptr<Oad> oad;//对象属性描述符     OAD，
    eGetResult resultType;
    shared_ptr<Dlt698Proctol> result;

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

};

}

#endif // RESULTNORMAL_H
