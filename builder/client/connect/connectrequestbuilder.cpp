#include "connectrequestbuilder.h"

using namespace Dlt698;

ConnectRequestBuilder::ConnectRequestBuilder()
{
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setPRM(_CliStart);
    m_request = dynamic_pointer_cast<Dlt698ConnectRequest>(this->link()->getBody());
}

ConnectRequestBuilder::ConnectRequestBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ClientBuilder(apdu)
{
    this->client()->setSevType(_ConnectRequest);
    m_request = dynamic_pointer_cast<Dlt698ConnectRequest>(this->link()->getBody());
}

shared_ptr<Dlt698ConnectRequest> ConnectRequestBuilder::request() const
{
    return m_request;
}

void ConnectRequestBuilder::setRequest(const shared_ptr<Dlt698ConnectRequest> &request)
{
    m_request = request;
}

