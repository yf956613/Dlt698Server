#ifndef LINKAPDUBUILDER_H
#define LINKAPDUBUILDER_H

#include "builder/apdubuilder.h"
#include "link/dlt698linkapdu.h"

namespace Dlt698 {

class LinkApduBuilder : public ApduBuilder
{
public:
    LinkApduBuilder();
    LinkApduBuilder(shared_ptr<Dlt698Apdu> apdu);


    shared_ptr<Dlt698LinkApdu> link() const;
    void setLink(const shared_ptr<Dlt698LinkApdu> &link);

private:
    shared_ptr<Dlt698LinkApdu> m_link;

    // ApduBuilder interface
public:
    virtual vector<BYTE> asduBuild() override;
};

}

#endif // LINKAPDUBUILDER_H
