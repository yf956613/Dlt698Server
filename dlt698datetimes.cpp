#include "dlt698datetimes.h"
#include <QString>

Dlt698DateTimeS::Dlt698DateTimeS(Data *parent)
    : Data(parent)
{
    this->setDataType(this->getTypeByName(typeid(*this).name()));
}

Dlt698DateTimeS::Dlt698DateTimeS(Dlt698::Data &other, Data *parent)
    : Data(other, parent)
{
   *this = other;
}

Dlt698DateTimeS::Dlt698DateTimeS(Dlt698DateTimeS &other, Data *parent)
    : Data(other, parent)
{
    *this = other;
}

Dlt698DateTimeS &Dlt698DateTimeS::operator=(const Dlt698DateTimeS &other)
{
    if(this == &other)
        return *this;
    this->year = other.year;
    this->month = other.month;
    this->day = other.day;
    this->hour = other.hour;
    this->minute = other.minute;
    this->second = other.second;
    return *this;
}

Dlt698::Data &Dlt698DateTimeS::operator=(Dlt698::Data &other)
{
    return Dlt698::dynamicCopy(*this, other);
}

void Dlt698DateTimeS::decode(const vector<BYTE> &res, size_t &pos)
{
    this->baseDecode(res, pos, this->year);
    this->baseDecode(res, pos, (BYTE*)&this->month, this->size);
}

void Dlt698DateTimeS::encode(vector<BYTE> &res)
{
    this->baseEncode(res, this->year);
    this->baseEncode(res, (BYTE*)&this->month, this->size);
}

long_unsigned_c Dlt698DateTimeS::getYear() const
{
    return year;
}

void Dlt698DateTimeS::setYear(const long_unsigned_c &value)
{
    year = value;
}

unsigned_c Dlt698DateTimeS::getMonth() const
{
    return month;
}

void Dlt698DateTimeS::setMonth(const unsigned_c &value)
{
    month = value;
}

unsigned_c Dlt698DateTimeS::getDay() const
{
    return day;
}

void Dlt698DateTimeS::setDay(const unsigned_c &value)
{
    day = value;
}

unsigned_c Dlt698DateTimeS::getHour() const
{
    return hour;
}

void Dlt698DateTimeS::setHour(const unsigned_c &value)
{
    hour = value;
}

unsigned_c Dlt698DateTimeS::getMinute() const
{
    return minute;
}

void Dlt698DateTimeS::setMinute(const unsigned_c &value)
{
    minute = value;
}

unsigned_c Dlt698DateTimeS::getSecond() const
{
    return second;
}

void Dlt698DateTimeS::setSecond(const unsigned_c &value)
{
    second = value;
}

void Dlt698DateTimeS::setDateTimeS(timeval &tv)
{
    struct tm* gmtm = localtime(&tv.tv_sec);
    this->year = gmtm->tm_year + 1900;
    this->month = gmtm->tm_mon + 1;
    this->day = gmtm->tm_mday;
    this->hour = gmtm->tm_hour;
    this->minute = gmtm->tm_min;
    this->second = gmtm->tm_sec;
}

string Dlt698DateTimeS::toString()
{
    return QString("%1-%2-%3 %4:%5:%6")
            .arg(this->year, 4, 10, QLatin1Char('0'))
            .arg(this->month, 2, 10, QLatin1Char('0'))
            .arg(this->day, 2, 10, QLatin1Char('0'))
            .arg(this->hour, 2, 10, QLatin1Char('0'))
            .arg(this->minute, 2, 10, QLatin1Char('0'))
            .arg(this->second, 2, 10, QLatin1Char('0'))
            .toStdString();
}

Dlt698::Data *Dlt698DateTimeS::clone(Data *parent)
{
    return new Dlt698DateTimeS(*this, parent);
}
