#include "connectresponsebuilder.h"

using namespace Dlt698;

ConnectResponseBuilder::ConnectResponseBuilder()
{
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setPRM(_CliStart);

    this->server()->setSevType(_ConnectResponse);
    m_response = dynamic_pointer_cast<Dlt698ConnectResponse>(this->server()->getBody());
}

ConnectResponseBuilder::ConnectResponseBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ServerBuilder(apdu)
{
    if(this->server())
    m_response = dynamic_pointer_cast<Dlt698ConnectResponse>(this->server()->getBody());
}

shared_ptr<Dlt698ConnectResponse> ConnectResponseBuilder::response() const
{
    return m_response;
}

void ConnectResponseBuilder::setResponse(const shared_ptr<Dlt698ConnectResponse> &response)
{
    m_response = response;
}
