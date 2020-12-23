#ifndef DLT698DAR_H
#define DLT698DAR_H

#include "dlt698proctol.h"

namespace Dlt698 {

typedef enum _eDAR
{
    _Succ=0,//成功                 （0），
    _HardWareInvalid,//硬件失效             （1），
    _TemporaryInvalid,//暂时失效             （2），
    _RefuseReadWrite,//拒绝读写             （3），
    _ObjNoDefine,//对象未定义           （4），
    _ObjInterfaceUnConformity,//对象接口类不符合     （5），
    _ObjExist,//对象不存在           （6），
    _TypeUnConformity,//类型不匹配           （7），
    _OverstepBoundary,//越界                 （8），
    _DataBlockBad,//数据块不可用         （9），
    _FenFrameTransCancel,//分帧传输已取消       （10），
    _NotFenFrameTrans,//不处于分帧传输状态   （11），
    _BlockWriteCancel,//块写取消             （12），
    _NoExistBlockWriteState,//不存在块写状态       （13），
    _DatBlockIDInvalid,//数据块序号无效       （14），
    _PasswordError,//密码错/未授权        （15），
    _CommRateNoChange,//通信速率不能更改     （16），
    _YearZoneOver,//年时区数超           （17），
    _DayZoneOver,//日时段数超           （18），
    _RateOver,//费率数超             （19），
    _SecuritCertificateMisMatch,//安全认证不匹配       （20），
    _Recharge,//重复充值             （21），
    _ESAMFail,//ESAM验证失败        （22），
    _SecuritFail,//安全认证失败         （23），
    _ClientNoMismatch,//客户编号不匹配       （24），
    _RechargeTimesErr,//充值次数错误         （25），
    _BuyEletriOver,//购电超囤积           （26），
    _AddrException,//地址异常             （27），
    _SymmDecryptErr,//对称解密错误         （28），
    _UnsymmDecryptErr,//非对称解密错误       （29），
    _AutographErr,//签名错误             （30），
    _MeterHangup,//电能表挂起           （31），
    _TimeStampInvalid,//时间标签无效          (32)，
    _RequestTimeOut,//请求超时             （33），
    _ESAM_P1P2_Err,//ESAM的P1P2不正确    （34），
    _ESA_LC_Err,//ESAM的LC错误        （35），
    _Other = 255//其它                 （255）

}eDAR;

class DAR : public Dlt698Proctol
{
public:
    DAR(eDAR data = _Succ);

    // Dlt698Proctol interface
public:
    virtual void decode(const vector<BYTE> &res, size_t &pos) override;
    virtual void encode(vector<BYTE> &res) override;

private:
    eDAR m_data;
};

}



#endif // DAR_H
