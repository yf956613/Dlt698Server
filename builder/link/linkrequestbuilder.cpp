#include "linkrequestbuilder.h"

using namespace Dlt698;

LinkRequestBuilder::LinkRequestBuilder()
{
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setDIR(_SevSend);

    this->link()->setSevType(_LinkRequest);
    m_request = dynamic_pointer_cast<Dlt698LinkRequest>(this->link()->getBody());
}

LinkRequestBuilder::LinkRequestBuilder(shared_ptr<Dlt698Apdu> apdu)
    : LinkApduBuilder(apdu)
{
    if(this->link())
    m_request = dynamic_pointer_cast<Dlt698LinkRequest>(this->link()->getBody());
}

shared_ptr<Dlt698LinkRequest> LinkRequestBuilder::request() const
{
    return m_request;
}

void LinkRequestBuilder::setRequest(const shared_ptr<Dlt698LinkRequest> &request)
{
    m_request = request;
}
