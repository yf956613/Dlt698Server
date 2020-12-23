#ifndef APDUBUILDER_H
#define APDUBUILDER_H

#include "apdu/dlt698apdu.h"

namespace Dlt698 {

class ApduBuilder
{
public:
    ApduBuilder();
    ApduBuilder(shared_ptr<Dlt698Apdu> apdu);

    vector<BYTE> build();
    virtual vector<BYTE> asduBuild();

    shared_ptr<Dlt698Apdu> apdu() const;
    void setApdu(const shared_ptr<Dlt698Apdu> &apdu);

private:
    shared_ptr<Dlt698Apdu> m_apdu;
};

}

#endif // APDUBUILDER_H
