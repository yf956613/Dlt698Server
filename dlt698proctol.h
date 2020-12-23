#ifndef DLT698PROCTOL_H
#define DLT698PROCTOL_H

#include "dlt698proctol_global.h"
#include "dlt698datatypes.h"
#include "dltstringbuffer.h"
#include "dltobject.h"
#include <vector>
#include <string.h>

using namespace std;

class DLT698PROCTOLSHARED_EXPORT Dlt698Proctol : public DltObject
{

public:
    virtual void decode(const vector<BYTE> &res, size_t &pos);

    virtual void encode(vector<BYTE> &res);

    virtual string toString();

    virtual ~Dlt698Proctol(){}

    string toHexString();

    vector<BYTE> toBytes();
public:
    static string byteToString(const BYTE convert_data[], int convert_len);

    static void baseEncode(vector<BYTE> &res, const void *data, size_t size);

    static void baseDecode(const vector<BYTE> &res, size_t &pos, void *data, size_t size);

    template<typename T>
    static void baseEncode(vector<BYTE> &res, T data);

    template<typename T>
    static void baseDecode(const vector<BYTE> &res, size_t &pos, T &data);

    template<typename T>
    static void enumEncode(vector<BYTE> &res, T data);

    template<typename T>
    static void enumDecode(const vector<BYTE> &res, size_t &pos, T &data);
};

template<typename T>
void Dlt698Proctol::enumDecode(const vector<BYTE> &res, size_t &pos, T &data)
{
    baseDecode(res, pos, &data, sizeof(BYTE));
}

template<typename T>
void Dlt698Proctol::enumEncode(vector<BYTE> &res, T data)
{
    baseEncode(res, (BYTE)data);
}

template<typename T>
void Dlt698Proctol::baseDecode(const vector<BYTE> &res, size_t &pos, T &data)
{
    T temp;
    baseDecode(res, pos, &temp, sizeof(T));
    nhSwap(&temp, sizeof(T));
    data = temp;
}

template<typename T>
void Dlt698Proctol::baseEncode(vector<BYTE> &res, T data)
{
    T temp = data;
    nhSwap(&temp, sizeof(T));
    baseEncode(res, &temp, sizeof(T));
}

#endif // DLT698PROCTOL_H
