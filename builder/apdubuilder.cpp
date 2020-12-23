#include "apdubuilder.h"

using namespace Dlt698;

ApduBuilder::ApduBuilder()
{
    m_apdu.reset(new Dlt698Apdu());
    m_apdu->getSA()->addAddrDat(0);
}

ApduBuilder::ApduBuilder(shared_ptr<Dlt698Apdu> apdu)
    : m_apdu(apdu)
{

}



vector<BYTE> ApduBuilder::build()
{
    m_apdu->setByASDU(this->asduBuild());
    return m_apdu->toBytes();
}

vector<BYTE> ApduBuilder::asduBuild()
{
    return m_apdu->getByASDU();
}

shared_ptr<Dlt698Apdu> ApduBuilder::apdu() const
{
    return m_apdu;
}

void ApduBuilder::setApdu(const shared_ptr<Dlt698Apdu> &apdu)
{
    m_apdu = apdu;
}
