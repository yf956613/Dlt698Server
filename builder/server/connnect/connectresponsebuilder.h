#ifndef CONNECTRESPONSEBUILDER_H
#define CONNECTRESPONSEBUILDER_H

#include "builder/server/serverbuilder.h"
#include "server/connect/dlt698connectresponse.h"

namespace Dlt698 {

class ConnectResponseBuilder : public ServerBuilder
{
public:
    ConnectResponseBuilder();


  private:
    shared_ptr<Dlt698ConnectResponse> m_response;
};

}

#endif // CONNECTRESPONSEBUILDER_H
