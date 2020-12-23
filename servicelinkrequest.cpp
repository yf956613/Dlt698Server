#include "servicelinkrequest.h"
#include "dlt698servicefactory.h"
#include "link/dlt698linkrequest.h"
#include "link/dlt698linkapdu.h"
#include "builder/link/linkrequestbuilder.h"

#include <QDebug>

using namespace Dlt698;

ServiceLinkRequest::ServiceLinkRequest()
{
    WORD type = this->getServiceType(_LinkRequest);
    Dlt698ServiceFactory::instance()->setService(type, this);
}

void ServiceLinkRequest::doService(ServiceRequest &request, ServiceResponse &response)
{
    qDebug() << "LinkRequest: 01";

    LinkRequestBuilder builder(request.getApdu());

    qDebug() << QString::fromStdString(builder.apdu()->toHexString());
}
