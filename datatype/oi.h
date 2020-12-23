#ifndef DLT698_OI_H
#define DLT698_OI_H

#include "data.h"

namespace Dlt698 {

class OI : public Data
{
public:
    OI(long_unsigned_c data = 0);

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

    long_unsigned_c data() const;
    void setData(const long_unsigned_c &data);

private:
    long_unsigned_c m_data;
};

}

#endif // OI_H
