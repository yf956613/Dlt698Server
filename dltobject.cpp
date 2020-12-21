#include "dltobject.h"

DltObject::DltObject()
{

}

string DltObject::toString()
{
    return "Object";
}

void DltObject::bigLittleSwap64(void *data)
{
    *(uint64_t*)data = ((*(uint64_t*)data) << 32) | ((*(uint64_t*)data) >> 32);
    bigLittleSwap32(data);
    bigLittleSwap32((uint32_t*)data + 1);
}

void DltObject::bigLittleSwap32(void *data)
{
    *(uint32_t*)data = ((*(uint32_t*)data) << 16) | ((*(uint32_t*)data) >> 16);
    bigLittleSwap16(data);
    bigLittleSwap16((uint16_t*)data + 1);
}

void DltObject::bigLittleSwap16(void *data)
{
    *(uint16_t*)data = ((*(uint16_t*)data) << 8) | ((*(uint16_t*)data) >> 8);
    bigLittleSwap8(data);
    bigLittleSwap8((uint8_t*)data + 1);
}

void DltObject::bigLittleSwap8(void *data)
{

}

void DltObject::nhSwap(void *data, size_t size)
{
    if(__BYTE_ORDER != __LITTLE_ENDIAN) {
        return;
    }
    switch (size) {
    case 8:
        bigLittleSwap64(data);
        break;
    case 4:
        bigLittleSwap32(data);
        break;
    case 2:
        bigLittleSwap16(data);
        break;
    default:
        bigLittleSwap8(data);
        break;
    }
}
