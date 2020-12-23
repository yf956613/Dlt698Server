#ifndef DLT698_STRUCT_H
#define DLT698_STRUCT_H

#include "data.h"

namespace Dlt698 {

class Struct : public Data
{
public:
    Struct(Data *parent = nullptr);
    Struct(Struct &other, Data *parent = nullptr);
    Struct(Data &other, Data *parent = nullptr);
    Struct& operator =(const Struct &other);

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    // Data interface
public:
    virtual Data *clone(Data *parent) override;

    virtual Data &operator =(Data &other) override;
};

}

#endif // STRUCT_H
