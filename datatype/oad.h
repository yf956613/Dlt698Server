#ifndef DLT698_OAD_H
#define DLT698_OAD_H

#include "data.h"
#include "basic.h"
#include "oi.h"

namespace Dlt698 {

class Oad : public Data
{
public:
    Oad(Data *parent = nullptr);
    Oad(Data &other, Data *parent = nullptr);
    Oad& operator =(Oad &other);

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    // Data interface
public:
    virtual Data *clone(Data *parent) override;
    virtual Data &operator =(Data &other) override;

    unsigned_c getAttrId() const;
    void setAttrId(const unsigned_c &value);

    unsigned_c getAttrFea() const;
    void setAttrFea(const unsigned_c &value);

    unsigned_c getElemIdx() const;
    void setElemIdx(const unsigned_c &value);

    OI getOi();
    void setOi(OI &oi);

private:
    OI m_oi;

    struct _tOAD
    {
        unsigned_c attrId:5;//属性标识
        unsigned_c attrFea:3;//属性特征
        unsigned_c elemIdx;//属性内元素索引
    }m_OAD;
};

}

#endif // OAD_H
