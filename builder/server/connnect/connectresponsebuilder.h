#ifndef CONNECTRESPONSEBUILDER_H
#define CONNECTRESPONSEBUILDER_H

#include "builder/server/serverbuilder.h"
#include "server/connect/dlt698connectresponse.h"

namespace Dlt698 {

class ConnectResponseBuilder : public ServerBuilder
{
public:
    ConnectResponseBuilder();
    ConnectResponseBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698ConnectResponse> response() const;
    void setResponse(const shared_ptr<Dlt698ConnectResponse> &response);

private:
    shared_ptr<Dlt698ConnectResponse> m_response;
};

}

#endif // CONNECTRESPONSEBUILDER_H
