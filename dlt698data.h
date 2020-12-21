#ifndef DLT698DATA_H
#define DLT698DATA_H

#include "dlt698proctol.h"
#include "memory"
#include "dlt698datetime.h"
#include "dlt698datetimes.h"
#include "datatype/data.h"
#include <QVariant>
#include <QObject>

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

    // DltObject interface
public:
    string toString() override;
};

#endif // DLT698DATA_H
