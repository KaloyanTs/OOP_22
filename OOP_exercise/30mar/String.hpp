#ifndef __STRING_HPP
#define __STRING_HPP
#include <iostream>
#include <cstring>
#include <cassert>
const size_t INPUT_MAX = 32;

class String
{
	char* str;
public:
	String() :str(nullptr) {}
	String(const char* s);
	String(const String&);
	~String();
	size_t length()const { return (str ? strlen(str) : 0); }
	String& operator=(const String& other);
	String operator+(const String& other)const;
	String& operator+=(const String& other);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
};

#endif