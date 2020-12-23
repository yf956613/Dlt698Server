#ifndef CONNECTREQUESTBUILDER_H
#define CONNECTREQUESTBUILDER_H

#include "builder/client/clientbuilder.h"
#include "client/connect/dlt698connectrequest.h"

namespace Dlt698 {

class ConnectRequestBuilder : public ClientBuilder
{
public:
    ConnectRequestBuilder();
    ConnectRequestBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698ConnectRequest> request() const;
    void setRequest(const shared_ptr<Dlt698ConnectRequest> &request);
    
private:
    shared_ptr<Dlt698ConnectRequest> m_request;
};

}

#endif // CONNECTREQUESTBUILDER_H
