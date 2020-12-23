#ifndef RESULTRECORD_H
#define RESULTRECORD_H

#include "datatype/oad.h"
#include "datatype/rcsd.h"

namespace Dlt698
{

enum eResponseData
{
    _DA=0,
    _DATA=1

};

class ResultRecord : public Dlt698Proctol
{
public:
    ResultRecord(eResponseData type = _DATA);

    shared_ptr<Dlt698Proctol> getData() const;
    Dlt698Proctol* bodyInstance(eResponseData type);

    eResponseData getChoiceRespDat() const;
    void setChoiceRespDat(const eResponseData &value);

    shared_ptr<Oad> getOad() const;
    void setOad(const shared_ptr<Oad> &value);

    shared_ptr<Rcsd> getRcsd() const;
    void setRcsd(const shared_ptr<Rcsd> &value);
private:
    shared_ptr<Oad> oad;//对象属性描述符     OAD，

    shared_ptr<Rcsd> rcsd;//一行记录N列属性描述符   RCSD

    eResponseData choiceRespDat;

    shared_ptr<Dlt698Proctol> data;

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

};

}



#endif // RESULTRECORD_H
