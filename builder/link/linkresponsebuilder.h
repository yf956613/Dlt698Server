#ifndef LINKRESPONSEBUILDER_H
#define LINKRESPONSEBUILDER_H

#include "linkapdubuilder.h"
#include "link/dlt698linkresponse.h"

namespace Dlt698{

class LinkResponseBuilder : public LinkApduBuilder
{
public:
    LinkResponseBuilder();
    LinkResponseBuilder(shared_ptr<Dlt698Apdu> apdu);

    shared_ptr<Dlt698LinkResponse> response() const;
    void setResponse(const shared_ptr<Dlt698LinkResponse> &response);

private:
    shared_ptr<Dlt698LinkResponse> m_response;
};

}

#endif // LINKRESPONSEBUILDER_H
