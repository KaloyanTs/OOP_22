#include <iostream>
#include "ServerFarm.hpp"

int main()
{
	ServerFarm f;
	WebServer w;
	w.read();
	f.addServer(w).print();
	w.read();
	f.addServer(w).print();
	w.read();
	f.addServer(w).print();
	f.findMaxNetwork();
	f.sort().print();
	char buf[BUF_MAX];
	std::cin.getline(buf, BUF_MAX);
	f -= buf;
	f.print();
	return 0;
}