#include "Time.hpp"

std::istream& operator>>(std::istream& is, Time& T)
{
    char c;
    is >> T.hour >> c >> T.minute;
    assert(T.minute < 60 && c == ':');
    return is;
}

Time operator+(const Time& t1, const Time& t2)
{
    unsigned resMinute = t1.getMinute() + t2.getMinute();
    return Time(t1.getHour() + t2.getHour() + (resMinute >= 60), (resMinute >= 60 ? resMinute - 60 : resMinute));
}

std::ostream& operator<<(std::ostream&os, const Time& T)
{
    return os << T.getHour() << ':' << T.getMinute();
}

Time& Time::operator=(const Time& other)
{
    if (this != &other)
    {
        hour = other.hour;
        minute = other.minute;
    }
    return *this;
}
