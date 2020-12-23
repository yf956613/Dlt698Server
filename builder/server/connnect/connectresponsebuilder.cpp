#include "connectresponsebuilder.h"

using namespace Dlt698;

ConnectResponseBuilder::ConnectResponseBuilder()
{
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setPRM(_CliStart);
    m_response = dynamic_pointer_cast<Dlt698ConnectResponse>(this->server()->getBody());
}

ConnectResponseBuilder::ConnectResponseBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ServerBuilder(apdu)
{
    this->server()->setSevType(_ConnectResponse);
    m_response = dynamic_pointer_cast<Dlt698ConnectResponse>(this->server()->getBody());
}
