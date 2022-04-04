#ifndef __TIME_HPP
#define __TIME_HPP
#include <iostream>
#include <cstring>
#include <cassert>

class Time
{
	unsigned hour, minute;
public:
	Time(unsigned _h = 0, unsigned _m = 0) :hour(_h), minute(_m) {}
	Time(const Time &other):hour(other.hour),minute(other.minute){}
	unsigned getHour()const { return hour; }
	unsigned getMinute()const { return minute; }
	void setHour(unsigned _h) { hour = _h; }
	void setMinute(unsigned _m) { minute = _m; }
	Time& operator=(const Time& other);
	friend std::istream& operator>>(std::istream& is, Time& T);
};

Time operator+(const Time& t1, const Time& t2);
std::ostream& operator<<(std::ostream&, const Time& T);

#endif
