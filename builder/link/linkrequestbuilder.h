#ifndef LINKREQUESTBUILDER_H
#define LINKREQUESTBUILDER_H

#include "linkapdubuilder.h"
#include "link/dlt698linkrequest.h"

namespace Dlt698 {

class LinkRequestBuilder : public LinkApduBuilder
{
public:
    LinkRequestBuilder();
    LinkRequestBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698LinkRequest> request() const;
    void setRequest(const shared_ptr<Dlt698LinkRequest> &request);

private:
    shared_ptr<Dlt698LinkRequest> m_request;
};

}

#endif // LINKREQUESTBUILDER_H
