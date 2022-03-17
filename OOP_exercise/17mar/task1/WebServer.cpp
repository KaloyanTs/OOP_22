#include "WebServer.hpp"

WebServer::WebServer()
{
	*url = '\0';
	IPv4Address[0] = IPv4Address[1] = IPv4Address[2] = IPv4Address[3] = 0;
	*os = '\0';
	std::cout << "<WebServer created successfully.>\n";
}
WebServer::WebServer(const char *_url, int *IP_arr, const char *_os)
{
	strcpy(url, _url);
	strcpy(os, _os);
	for (unsigned i = 0; i < IP_COUNT; ++i)
		IPv4Address[i] = IP_arr[i];
	std::cout << "<WebServer created successfully.>\n";
}

unsigned WebServer::digitCount(unsigned n) const
{
	unsigned res = 0;
	while (n)
	{
		++res;
		n /= 10;
	}
	return res;
}

void WebServer::appendNum(char *&output, unsigned n) const
{
	output += digitCount(n);
	*output-- = '\0';
	do
	{
		*output-- = n % 10 + '0';
		n /= 10;
	} while (n);
	++output;
	while (*output)
		++output;
}

char *WebServer::IPtoString(char *res) const
{
	char *begining = res;
	for (unsigned i = 0; i < IP_COUNT; ++i)
	{
		appendNum(res, IPv4Address[i]);
		*res++ = '.';
		*res = '\0';
	}
	*--res = '\0';
	return begining;
}

bool WebServer::operator<(const WebServer &wS) const
{
	char bufThis[BUF_MAX];
	IPtoString(bufThis);
	char bufOther[BUF_MAX];
	wS.IPtoString(bufOther);
	return strcmp(bufThis, bufOther) < 0;
}

bool WebServer::operator==(const WebServer &wS) const
{
	return !strcmp(url, wS.url) &&
		   IPv4Address[0] == wS.IPv4Address[0] &&
		   IPv4Address[1] == wS.IPv4Address[1] &&
		   IPv4Address[2] == wS.IPv4Address[2] &&
		   IPv4Address[3] == wS.IPv4Address[3] &&
		   !strcmp(os, wS.os);
}
void WebServer::print() const
{
	std::cout << "URL: " << url
			  << "\tIPv4Address: ";
	for (unsigned i = 0; i < IP_COUNT; ++i)
	{
		if (i)
			std::cout << '.';
		std::cout << IPv4Address[i];
	}
	std::cout << "\tOS: " << os << '\n';
}

void WebServer::read()
{
	std::cout << "Enter server's URL: ";
	std::cin.getline(url, URL_MAX);
	std::cout << "Enter IP address: ";
	char dot;
	std::cin >> IPv4Address[0] >> dot;
	assert(dot == '.');
	std::cin >> IPv4Address[1] >> dot;
	assert(dot == '.');
	std::cin >> IPv4Address[2] >> dot;
	assert(dot == '.');
	std::cin >> IPv4Address[3];
	std::cout << "Enter operating system: ";
	std::cin.ignore();
	std::cin.getline(os, OS_MAX);
	std::cout << "<WebServer read successfully.>\n";
}

char *WebServer::webString(char *res) const
{
	char *begining = res;
	for (unsigned i = 0; i < IP_COUNT - 1; ++i)
	{
		appendNum(res, IPv4Address[i]);
		*res++ = '.';
		*res = '\0';
	}
	*--res = '\0';
	return begining;
}
