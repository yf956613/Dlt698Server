#ifndef SERVERBUILDER_H
#define SERVERBUILDER_H

#include "server/dlt698serverapdu.h"
#include "builder/apdubuilder.h"

namespace Dlt698 {

class ServerBuilder : public ApduBuilder
{
public:
    ServerBuilder();
    ServerBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698ServerApdu> server() const;
    void setServer(const shared_ptr<Dlt698ServerApdu> &server);

private:
    shared_ptr<Dlt698ServerApdu> m_server;

    // ApduBuilder interface
protected:
    virtual vector<BYTE> asduBuild() override;
};

}

#endif
