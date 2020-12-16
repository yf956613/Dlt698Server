#include "dlt698proctol.h"

void Dlt698Proctol::decode(const vector<BYTE> &res, size_t &pos)
{

}

void Dlt698Proctol::encode(vector<BYTE> &res)
{

}

string Dlt698Proctol::toString()
{
    return "Proctol";
}

string Dlt698Proctol::byteToString(const BYTE convert_data[], int convert_len)
{
    string frame = "";
    unsigned char high_hex;
    unsigned char low_hex;
    for (int i = 0; i < convert_len; i++)
    {
        high_hex = convert_data[i] >> 4;
        low_hex  = convert_data[i] & 0x0F;
        if (high_hex > 9)
        {
            high_hex = high_hex + '0' + 7;
        }
        else
        {
            high_hex = high_hex + '0';
        }

        if(low_hex > 9)
        {
            low_hex = low_hex + '0' + 7;
        }
        else
        {
            low_hex = low_hex + '0';
        }

        frame += high_hex;
        frame += low_hex;
        frame += " ";

    }
    return frame;
}

string Dlt698Proctol::toHexString()
{
    vector<BYTE> buff = this->toBytes();
    if(buff.size() == 0)
        return "";
    return this->byteToString(&buff[0], buff.size());
}

vector<BYTE> Dlt698Proctol::toBytes()
{
    vector<BYTE> buff;
    this->encode(buff);
    return buff;
}

void Dlt698Proctol::baseEncode(vector<BYTE> &res, const void *data, size_t size)
{
    if(data == NULL || size == 0)return;
    res.resize(res.size() + size, 0);
    memcpy(&res[res.size() - size], data, size);
}

void Dlt698Proctol::baseDecode(const vector<BYTE> &res, size_t &pos, void *data, size_t size)
{
    if(data == NULL || size > res.size() - pos)return;
    memcpy(data, &res[pos], size);
    pos += size;
}

void Dlt698Proctol::baseEncode(vector<BYTE> &res, uint16_t netshort)
{
    netshort = htons(netshort);
    baseEncode(res, &netshort, sizeof(uint16_t));
}

void Dlt698Proctol::baseEncode(vector<BYTE> &res, uint32_t netlong)
{
    netlong = htonl(netlong);
    baseEncode(res, &netlong, sizeof(uint32_t));
}

void Dlt698Proctol::baseDecode(const vector<BYTE> &res, size_t &pos, uint16_t &netshort)
{
    uint16_t buff;
    baseDecode(res, pos, &buff, sizeof(uint16_t));
    netshort = ntohs(buff);
}

void Dlt698Proctol::baseDecode(const vector<BYTE> &res, size_t &pos, uint32_t &netlong)
{
    uint32_t buff;
    baseDecode(res, pos, &buff, sizeof(uint32_t));
    netlong = ntohl(buff);
}

void Dlt698Proctol::baseEncode(vector<BYTE> &res, uint8_t netbyte)
{
    baseEncode(res, &netbyte, sizeof(BYTE));
}

void Dlt698Proctol::baseDecode(const vector<BYTE> &res, size_t &pos, uint8_t &netbyte)
{
    baseDecode(res, pos, &netbyte, sizeof(BYTE));
}

void Dlt698Proctol::baseEncode(vector<BYTE> &res, uint64_t netllong)
{
    if(__BYTE_ORDER == __LITTLE_ENDIAN)
    {
        netllong = (((unsigned long long )htonl((int)((netllong << 32) >> 32))) << 32) | (unsigned int)htonl((int)(netllong >> 32));
    }
    baseEncode(res, &netllong, sizeof(uint64_t));
}

void Dlt698Proctol::baseDecode(const vector<BYTE> &res, size_t &pos, uint64_t &netllong)
{
    uint64_t buff;
    baseDecode(res, pos, &buff, sizeof(uint64_t));
    if (__BYTE_ORDER == __LITTLE_ENDIAN)
    {
        netllong = (((unsigned long long )ntohl((int)((buff << 32) >> 32))) << 32) | (unsigned int)ntohl((int)(buff >> 32));
    }
    else netllong = buff;
}


