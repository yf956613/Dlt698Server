#include "linkresponsebuilder.h"

using namespace Dlt698;

LinkResponseBuilder::LinkResponseBuilder()
{
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setDIR(_CliSend);

    this->link()->setSevType(_LinkResponse);
    m_response = dynamic_pointer_cast<Dlt698LinkResponse>(this->link()->getBody());
}

LinkResponseBuilder::LinkResponseBuilder(shared_ptr<Dlt698Apdu> apdu)
    : LinkApduBuilder(apdu)
{
    if(this->link())
    m_response = dynamic_pointer_cast<Dlt698LinkResponse>(this->link()->getBody());
}

shared_ptr<Dlt698LinkResponse> LinkResponseBuilder::response() const
{
    return m_response;
}

void LinkResponseBuilder::setResponse(const shared_ptr<Dlt698LinkResponse> &response)
{
    m_response = response;
}
