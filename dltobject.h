#ifndef DLTOBJECT_H
#define DLTOBJECT_H

#include <string>
#include <memory.h>

using namespace std;

class DltObject
{
public:
    DltObject();

    virtual string toString();

    static void bigLittleSwap64(void *data);

    static void bigLittleSwap32(void *data);

    static void bigLittleSwap16(void *data);

    static void bigLittleSwap8(void *data);

    static void nhSwap(void* data, size_t size);
};

#endif // DLTOBJECT_H
