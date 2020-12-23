#ifndef CLIENTBUILDER_H
#define CLIENTBUILDER_H

#include "client/dlt698clientapdu.h"
#include "builder/apdubuilder.h"

namespace Dlt698 {

class ClientBuilder : public ApduBuilder
{
public:
    ClientBuilder();
    ClientBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698ClientApdu> client() const;
    void setClient(const shared_ptr<Dlt698ClientApdu> &client);

    virtual vector<BYTE> asduBuild() override;
private:
    shared_ptr<Dlt698ClientApdu> m_client;

};

}

#endif
