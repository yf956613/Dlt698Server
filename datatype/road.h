#ifndef DLT698_ROAD_H
#define DLT698_ROAD_H

#include "data.h"
#include "oad.h"
#include "row.h"

namespace Dlt698 {

class Road : public Data
{
public:
    Road();

    // Dlt698Proctol interface
public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;

    shared_ptr<Oad> oad() const;
    void setOad(const shared_ptr<Oad> &oad);

    shared_ptr<Row<Oad> > poad() const;
    void setPoad(const shared_ptr<Row<Oad> > &poad);

private:
    shared_ptr<Oad> m_oad;
    shared_ptr<Row<Oad>> m_poad;
};
}



#endif // ROAD_H
