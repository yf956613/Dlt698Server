#include "clientbuilder.h"

ClientBuilder::ClientBuilder()
{
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setDIR(_CliSend);
    ctrl->setFunc(_UserData);
    m_client.reset(new Dlt698ClientApdu());
}

ClientBuilder::ClientBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ApduBuilder(apdu)
{
    m_client.reset(new Dlt698ClientApdu());

    size_t pos = 0;
    m_client->decode(apdu->getByASDU(), pos);
}

shared_ptr<Dlt698ClientApdu> ClientBuilder::client() const
{
    return m_client;
}

void ClientBuilder::setClient(const shared_ptr<Dlt698ClientApdu> &client)
{
    m_client = client;
}

vector<BYTE> ClientBuilder::asduBuild()
{
    return m_client->toBytes();
}
