#include "Date.h"
#include <cstring>
#include <stdexcept>

int getIntFromStr(const char* str, int strLen) {
    int result = 0;
    for (int i = 0; i < strLen; i++)
    {
        result *= 10;
        result += (int)str[i] - '0';
    }
    return result;
}

Date::Date()
{
    day = 0;
    month = 0;
    year = 0;
}

Date::Date(int day, int month, int year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

Date::Date(const char* str)
{
    setDay(getIntFromStr(str, 2));
    setMonth(getIntFromStr(str + 3, 2));
    setYear(getIntFromStr(str + 6, 4));
}

void Date::setDay(int day)
{
    if (day > 0 && day < 31)
        this->day = day;
    else {
        this->day = 0;
        throw std::runtime_error("Invalid Date Input!");
    }
}

void Date::setMonth(int month)
{
    if (month > 0 && month < 13)
        this->month = month;
    else 
    {
        this->month = 0;
        throw std::runtime_error("Invalid Date Input!");
    }
}

void Date::setYear(int year)
{
    if (year > 1969 && year < 2033)
    this->year = year - 1969;
    else
    {
        this->year = 0;
        throw std::runtime_error("Invalid Date Input!");
    }
}

int Date::getYear() const
{
    return year + 1969;
}

void Date::print(std::ostream& os) const
{
    os << day << '/' << month << '/' << getYear() << ' ';
}
