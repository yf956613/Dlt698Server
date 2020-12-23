#include "linkapdubuilder.h"

using namespace Dlt698;

LinkApduBuilder::LinkApduBuilder()
{    
    shared_ptr<Dlt698CtrlDomain> ctrl = this->apdu()->getCtrl();
    ctrl->setPRM(_SevStart);
    ctrl->setFunc(_LinkManager);
    m_link.reset(new Dlt698LinkApdu());
}

LinkApduBuilder::LinkApduBuilder(shared_ptr<Dlt698Apdu> apdu)
    : ApduBuilder(apdu)
{
    m_link.reset(new Dlt698LinkApdu());

    size_t pos = 0;
    m_link->decode(apdu->getByASDU(), pos);
}

shared_ptr<Dlt698LinkApdu> LinkApduBuilder::link() const
{
    return m_link;
}

void LinkApduBuilder::setLink(const shared_ptr<Dlt698LinkApdu> &link)
{
    m_link = link;
}

vector<BYTE> LinkApduBuilder::asduBuild()
{
    return m_link->toBytes();
}
