#ifndef __SERVER_FARM_HPP
#define __SERVER_FARM_HPP
#include <iostream>
#include <cstring>
#include "WebServer.hpp"

class ServerFarm
{
	WebServer **servers;
	size_t count;
	char *name;
	void dealloc(WebServer **&arr, unsigned n);
	void copy(const ServerFarm &sF);

public:
	ServerFarm();
	ServerFarm(const ServerFarm &sF);
	ServerFarm &addServer(const WebServer &wS);
	ServerFarm &operator-=(const char *ip);
	unsigned countInNetwork(const char *web) const;
	void findMaxNetwork() const;
	const ServerFarm &operator=(const ServerFarm &sF);
	void print() const;
	ServerFarm &sort();
	~ServerFarm();
};

#endif
