#ifndef DLT698CTRLDOMAIN_H
#define DLT698CTRLDOMAIN_H

#include "dlt698proctol.h"

namespace Dlt698 {

typedef enum _ePRM{
    _SevStart = 0,
    _CliStart
}ePrm;

typedef enum _eDIR{
    _CliSend = 0,
    _SevSend
}eDir;

typedef enum _eFUNC{
    _LinkManager = 1,
    _UserData = 3
}eFunc;

typedef enum _eSC{
    _DefaultSc,
    _ScAdd33H = 1
}eSc;

typedef enum _eFRAME{
    _TotalFrame = 0,
    _PartFrame = 1
}eFrame;

}

using namespace Dlt698;

class Dlt698CtrlDomain : public Dlt698Proctol
{
public:
    Dlt698CtrlDomain();

public:
    void decode(const vector<BYTE> &res, size_t &pos) override;
    void encode(vector<BYTE> &res) override;
    string toString() override;

    eFunc getFunc() const;
    void setFunc(const eFunc &value);

    BYTE getRes() const;
    void setRes(const BYTE &value);

    eFrame getFrame() const;
    void setFrame(const eFrame &value);

    ePrm getPRM() const;
    void setPRM(const ePrm &value);

    eDir getDIR() const;
    void setDIR(const eDir &value);

private:
    struct _tCONTROLDOMAIN
    {
        BYTE  func:3; //功能吗 0,2,4...7保留  1：链路管理 3：用户数据
        BYTE  sc:1;//扰码标志 1：扰码格式加33H 0：默认格式
        BYTE  res:1;
        BYTE  frame:1;//分帧标志 1:用户数据为APDU片段 0:用户数据为完整APDU
        BYTE  PRM:1;//启动标志   1：此帧由客户机发起 0：此帧由服务器发起
        BYTE  DIR:1;//传输方向   1：此帧由服务器发出的  0：此帧由客户机发出的

        //DIR  PRM   含义
        // 0    0    客户机对服务器上报的响应
        // 0    1    客户机发起的请求
        // 1    0    服务器发起的上报
        // 1    1    服务器对客户机请求的响应

    }CtrlDomain;
};

#endif // DLT698CTRLDOMAIN_H
