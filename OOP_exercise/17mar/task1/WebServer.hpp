#ifndef __WEBSERVER_HPP
#define __WEBSERVER_HPP
#include <iostream>
#include <cstring>
#include <cassert>
const unsigned URL_MAX = 500;
const unsigned IP_COUNT = 4;
const unsigned OS_MAX = 20;
const unsigned BUF_MAX = 64;

class WebServer
{
	char url[URL_MAX + 1];
	unsigned IPv4Address[IP_COUNT];
	char os[OS_MAX + 1];
	void appendNum(char *&output, unsigned n) const;
	unsigned digitCount(unsigned n) const;

public:
	WebServer();
	WebServer(const char *_url, int *IP_arr, const char *_os);
	char *IPtoString(char *res) const;
	char *webString(char *res) const;
	bool operator<(const WebServer &wS) const;
	bool operator==(const WebServer &wS) const;
	void print() const;
	void read();
};

#endif
