#ifndef DATAFACTORY_H
#define DATAFACTORY_H

#include <unordered_map>
#include "basic.h"
#include "struct.h"
#include "array.h"
#include "common/dlt698datetimes.h"
#include "oad.h"

namespace Dlt698 {

typedef Struct d_struct;
typedef Array<Data> d_array;

typedef Basic<integer_c> d_int;
typedef Basic<unsigned_c> d_uint;
typedef Basic<long_c> d_long;
typedef Basic<long_unsigned_c> d_ulong;
typedef Basic<double_long_c> d_llong;
typedef Basic<double_long_unsigned_c> d_ullong;
typedef Basic<long64_c> d_long64;
typedef Basic<long64_unsigned_c> d_ulong64;
typedef Basic<bool_c> d_bool;
typedef Basic<enum_c> d_enum;

typedef Dlt698DateTimeS d_datetimes;


class DataFactory
{
public:
    static DataFactory& instance();

    const unique_ptr<Data>& getData(eDataType type);
    void addData(eDataType type, Data* data);

    Data* dataClone(eDataType type, Data* parent = nullptr);

private:
    DataFactory();

    unordered_map<int, unique_ptr<Data>> m_dataMap;

    static DataFactory m_instance;
};

}

#endif // DATAFACTORY_H
