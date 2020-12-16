#ifndef DLT698DATA_H
#define DLT698DATA_H

#include "dlt698proctol.h"
#include "memory"
#include "dlt698datetime.h"
#include "dlt698datetimes.h"
#include <QVariant>

class Dlt698Data : public Dlt698Proctol
{
public:
    Dlt698Data(eDataType type = t_null);

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    eDataType getETyp() const;
    void setETyp(const eDataType &value);

    QVariant getData() const;
    const QVariant& data() const;
    QVariant& data();
    void setData(const QVariant &data);

    QList<Dlt698Data> toList() const;
    Dlt698DateTime toDateTime() const;
    Dlt698DateTimeS toDateTimeS() const;
private:
    eDataType eTyp;

    QVariant m_data;

    // DltObject interface
public:
    string toString() override;
};

Q_DECLARE_METATYPE(Dlt698Data)

#endif // DLT698DATA_H
