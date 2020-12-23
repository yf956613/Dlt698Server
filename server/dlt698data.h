#ifndef DLT698DATA_H
#define DLT698DATA_H

#include "dlt698proctol.h"
#include "memory"
#include "common/dlt698datetime.h"
#include "common/dlt698datetimes.h"
#include "datatype/data.h"

class Dlt698Data : public Dlt698Proctol
{
public:
    Dlt698::Data *getChild() const;
    void setChild(Dlt698::Data *data);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

private:
    Dlt698::Data m_data;
};

#endif // DLT698DATA_H
