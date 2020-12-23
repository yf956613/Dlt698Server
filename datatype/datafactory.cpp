#include "datafactory.h"

using namespace Dlt698;

DataFactory DataFactory::m_instance = DataFactory();

DataFactory::DataFactory()
{
    if(!m_dataMap.empty())
        return;

    this->addData(t_datetime_s, new d_datetimes());

    this->addData(t_null, new Data());

    this->addData(t_structure, new d_struct());
    this->addData(t_array, new d_array());

    this->addData(t_integer, new d_int());
    this->addData(t_unsigned, new d_uint());
    this->addData(t_long, new d_long());
    this->addData(t_long_unsigned, new d_ulong());
    this->addData(t_double_long, new d_llong());
    this->addData(t_double_long_unsigned, new d_ullong());
    this->addData(t_long64, new d_long64());
    this->addData(t_long64_unsigned, new d_ulong64());
    this->addData(t_bool, new d_bool());
    this->addData(t_enum, new d_enum());
}

DataFactory &Dlt698::DataFactory::instance()
{
    return m_instance;
}

const unique_ptr<Data> &DataFactory::getData(eDataType type)
{
    try {
        return m_dataMap.at(type);
    }
    catch(std::out_of_range) {
        return m_dataMap.at(t_null);
    }
}

void DataFactory::addData(eDataType type, Data* data)
{
    Data::addNameType(typeid(*data).name(), type);
    data->setDataType(type);
    this->m_dataMap[type] = unique_ptr<Data>(data);
}

Data *DataFactory::dataClone(eDataType type, Data *parent)
{
    return this->getData(type)->clone(parent);
}
