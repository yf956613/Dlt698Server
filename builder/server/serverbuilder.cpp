#include "serverbuilder.h"

using namespace Dlt698;

ServerBuilder::ServerBuilder()
{
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setDIR(_SevSend);
    ctrl->setFunc(_UserData);
    m_server.reset(new Dlt698ServerApdu());
}

ServerBuilder::ServerBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ApduBuilder(apdu)
{
    m_server.reset(new Dlt698ServerApdu());

    size_t pos = 0;
    m_server->decode(apdu->getByASDU(), pos);
}

shared_ptr<Dlt698ServerApdu> ServerBuilder::server() const
{
    return m_server;
}

void ServerBuilder::setServer(const shared_ptr<Dlt698ServerApdu> &server)
{
    m_server = server;
}

vector<BYTE> ServerBuilder::asduBuild()
{
    return m_server->toBytes();
}
