#ifndef __VIRUS_HPP
#define __VIRUS_HPP
#include <iostream>
#include <cstring>
#include <cassert>
const size_t INPUT_MAX = 32;

class Virus
{
	char* name;
	unsigned severity;
	void copy(const Virus& other);
	void clean();
	void print(std::ostream &os)const;
public:
	Virus();
	Virus(const char* _name, unsigned _w);
	Virus(const Virus& other);
	const Virus& operator=(const Virus& other);
	const char* getName()const { return name; }
	void setName(const char* _name);
	void setSeverity(unsigned _severity) { severity=_severity; }
	unsigned getSeverity()const { return severity; }
	void read(std::istream& is);
	bool operator<(const Virus& other)const { return severity < other.severity; }
	bool operator>(const Virus& other)const { return severity > other.severity; }
	bool operator>=(const Virus& other)const { return severity >= other.severity; }
	bool operator<=(const Virus& other)const { return severity <= other.severity; }
	friend std::istream& operator>>(std::istream& os, Virus& V);
	~Virus();
};

std::ostream& operator<<(std::ostream& os,const Virus& V);

#endif
