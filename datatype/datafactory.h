#ifndef DATAFACTORY_H
#define DATAFACTORY_H

#include <unordered_map>
#include "databasic.h"
#include "datastruct.h"
#include "dataarray.h"
#include "dlt698datetimes.h"

namespace Dlt698 {

typedef DataStruct d_struct;
typedef DataArray<Data> d_array;

typedef DataBasic<integer_c> d_int;
typedef DataBasic<unsigned_c> d_uint;
typedef DataBasic<long_c> d_long;
typedef DataBasic<long_unsigned_c> d_ulong;
typedef DataBasic<double_long_c> d_llong;
typedef DataBasic<double_long_unsigned_c> d_ullong;
typedef DataBasic<long64_c> d_long64;
typedef DataBasic<long64_unsigned_c> d_ulong64;
typedef DataBasic<bool_c> d_bool;
typedef DataBasic<enum_c> d_enum;

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
