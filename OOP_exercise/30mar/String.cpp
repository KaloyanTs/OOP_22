#include "String.hpp"

String::String(const char *s) : str(new char[strlen(s) + 1])
{
	assert(str);
	strcpy(str, s);
}

String::String(const String &S) : str(new char[strlen(S.str) + 1])
{
	assert(str);
	strcpy(str, S.str);
}

String::~String()
{
	delete[] str;
}

String &String::operator=(const String &other)
{
	if (this != &other)
	{
		delete[] str;
		str = new char[strlen(other.str) + 1];
		assert(str);
		strcpy(str, other.str);
	}
	return *this;
}

String String::operator+(const String &other) const
{
	char *buf = new char[strlen(str) + strlen(other.str) + 1];
	assert(buf);
	strcpy(buf, str);
	strcat(buf, other.str);
	return String(buf);
}

String &String::operator+=(const String &other)
{
	char *newStr = new char[(str ? strlen(str) : 0) +
							(other.str ? strlen(other.str) : 0) + 1];
	assert(str);
	if (str)
		strcpy(newStr, str);
	if (other.str)
		strcat(newStr, other.str);
	delete[] str;
	str = newStr;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const String &S)
{
	return os << (S.str ? S.str : "<empty>");
}

std::istream &operator>>(std::istream &is, String &S)
{
	char buf[INPUT_MAX];
	is.getline(buf, INPUT_MAX);
	delete[] S.str;
	S.str = new char[strlen(buf) + 1];
	assert(S.str);
	strcpy(S.str, buf);
	return is;
}

String upper(const String &S)
{
	String res = S;
	for (char *i = res.str; *i; ++i)
		if (*i >= 'a' && *i <= 'z')
			*i += 'A' - 'a';
	return res;
}

String lower(const String &S)
{
	String res = S;
	for (char *i = res.str; *i; ++i)
		if (*i >= 'A' && *i <= 'Z')
			*i += 'a' - 'A';
	return res;
}

void swap(String &s1,String &s2)
{
	char *buf = s1.str;
	s1.str = s2.str;
	s2.str = buf;
}
