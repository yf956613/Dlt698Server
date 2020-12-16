#include "dlt698data.h"
#include <QDebug>

Dlt698Data::Dlt698Data(eDataType type) : eTyp(type)
{

}

void Dlt698Data::decode(const vector<BYTE> &res, size_t &pos)
{
    if(pos >= res.size())
        return;
    this->eTyp = (eDataType)res.at(pos ++);
    switch (this->eTyp) {
    case t_null:
        break;
    case t_structure:
    case t_array:
    {
        QList<Dlt698Data> var;
        Dlt698Data child;
        BYTE num = res.at(pos ++);
        while(num --)
        {
            child.decode(res, pos);
            var.append(child);
        }
        m_data.setValue(var);
    }
        break;
    case t_bool:
    {
        uint8_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(static_cast<bool_c>(var));
    }
        break;
    case t_utf8_string:

    case t_visible_string:

    case t_octet_string:

    case t_bit_string:
    {
        BYTE num = res.at(pos ++);
        QString var(num);
        this->baseDecode(res, pos, var.data(), num);
        m_data.setValue(var);
    }
        break;
    case t_double_long:
    {
        uint32_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(static_cast<double_long_c>(var));
    }
        break;
    case t_double_long_unsigned:
    {
        uint32_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(static_cast<double_long_unsigned_c>(var));
    }
        break;
    case t_bcd:

        break;
    case t_integer:
    {
        uint8_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(static_cast<integer_c>(var));
    }
        break;
    case t_long:
    {
        uint16_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(static_cast<double_long_c>(var));
    }
        break;
    case t_unsigned:
    {
        uint8_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(static_cast<unsigned_c>(var));
    }
        break;
    case t_long_unsigned:
    {
        uint16_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(static_cast<long_unsigned_c>(var));
    }
        break;
    case t_long64:
    {
        uint64_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(static_cast<long long>(var));
    }
        break;
    case t_long64_unsigned:
    {
        uint64_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(static_cast<unsigned long long>(var));
    }
        break;
    case t_date_time:
    {
        Dlt698DateTime var;
        var.decode(res, pos);
        m_data = QVariant::fromValue(var);
    }
        break;
    case t_datetime_s:
    {
        Dlt698DateTimeS var;
        var.decode(res, pos);
        m_data = QVariant::fromValue(var);
    }
        break;
    case t_enum:
    {
        uint8_t var;
        this->baseDecode(res, pos, var);
        m_data.setValue(var);
    }
        break;
    default:
        break;
    }
}

void Dlt698Data::encode(vector<BYTE> &res)
{
    res.push_back((BYTE)this->eTyp);
    switch (this->eTyp) {
    case t_null:
        break;
    case t_structure:
    case t_array:
    {
        QList<Dlt698Data> var = m_data.value<QList<Dlt698Data>>();
        res.push_back(var.size());
        for(auto &k : var)
        {
            k.encode(res);
        }
    }
        break;
    case t_bool:
    {
        this->baseEncode(res, static_cast<uint8_t>(m_data.toBool()));
    }
        break;
    case t_utf8_string:

    case t_visible_string:

    case t_octet_string:

    case t_bit_string:
    {
        QString var = m_data.toString();
        this->baseEncode(res, static_cast<uint8_t>(var.size()));
        this->baseEncode(res, var.data(), var.size());
    }
        break;
    case t_double_long:
        this->baseEncode(res, static_cast<uint32_t>(m_data.toInt()));
        break;
    case t_double_long_unsigned:
        this->baseEncode(res, static_cast<uint32_t>(m_data.toUInt()));
        break;
    case t_bcd:

        break;
    case t_integer:
        this->baseEncode(res, static_cast<uint8_t>(m_data.toInt()));
        break;
    case t_long:
        this->baseEncode(res, static_cast<uint16_t>(m_data.toInt()));
        break;
    case t_unsigned:
        this->baseEncode(res, static_cast<uint8_t>(m_data.toUInt()));
        break;
    case t_long_unsigned:
        this->baseEncode(res, static_cast<uint16_t>(m_data.toUInt()));
        break;
    case t_long64:
        this->baseEncode(res, static_cast<uint64_t>(m_data.toLongLong()));
        break;
    case t_long64_unsigned:
        this->baseEncode(res, static_cast<uint64_t>(m_data.toULongLong()));
        break;
    case t_date_time:
        m_data.value<Dlt698DateTime>().encode(res);
    case t_datetime_s:
        m_data.value<Dlt698DateTimeS>().encode(res);
        break;
    case t_enum:
        this->baseEncode(res, static_cast<uint8_t>(m_data.toInt()));
        break;
    default:
        break;
    }
}

eDataType Dlt698Data::getETyp() const
{
    return eTyp;
}

void Dlt698Data::setETyp(const eDataType &value)
{
    eTyp = value;
}

QVariant Dlt698Data::getData() const
{
    return m_data;
}

const QVariant &Dlt698Data::data() const
{
    return m_data;
}

QVariant &Dlt698Data::data()
{
    return m_data;
}

void Dlt698Data::setData(const QVariant &data)
{
    m_data = data;
}

QList<Dlt698Data> Dlt698Data::toList() const
{
    if(m_data.canConvert<QList<Dlt698Data>>())
        return m_data.value<QList<Dlt698Data>>();
    return {};
}

Dlt698DateTime Dlt698Data::toDateTime() const
{
    if(m_data.canConvert<Dlt698DateTime>())
        return m_data.value<Dlt698DateTime>();
    return {};
}

Dlt698DateTimeS Dlt698Data::toDateTimeS() const
{
    if(m_data.canConvert<Dlt698DateTimeS>())
        return m_data.value<Dlt698DateTimeS>();
    return {};
}

string Dlt698Data::toString()
{
    DltStringBuffer buffer;
    buffer.append("DATA类型", this->eTyp);

    return buffer.toString();
}
