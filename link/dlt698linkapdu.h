#ifndef DLT698LINKAPDU_H
#define DLT698LINKAPDU_H

#include "dlt698proctol.h"

namespace Dlt698 {

typedef enum _eLinkAPDU
{
    ///     预连接请求
    _LinkRequest = 1,
    ///     预连接响应
    _LinkResponse = 129,

}eLinkAPDU;

}

using namespace Dlt698;

class Dlt698LinkApdu : public Dlt698Proctol
{
public:
    Dlt698LinkApdu(eLinkAPDU type = _LinkRequest);

public:
    void decode(const vector<BYTE> &res, size_t &pos);
    void encode(vector<BYTE> &res);

    eLinkAPDU getSevType() const;
    void setSevType(const eLinkAPDU &value);

    shared_ptr<Dlt698Proctol> getBody() const;
    Dlt698Proctol* bodyInstance(eLinkAPDU type);

private:
    eLinkAPDU sevType;

    shared_ptr<Dlt698Proctol> body;
};

#endif // DLT698LINKAPDU_H
