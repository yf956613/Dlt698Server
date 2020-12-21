#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include "data.h"

namespace Dlt698 {

class DataStruct : public Data
{
public:
    DataStruct(Data *parent = nullptr);
    DataStruct(DataStruct &other, Data *parent = nullptr);
    DataStruct(Data &other, Data *parent = nullptr);
    DataStruct& operator =(const DataStruct &other);

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


#endif // DATASTRUCT_H
