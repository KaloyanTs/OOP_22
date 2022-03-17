#include "ServerFarm.hpp"

void ServerFarm::dealloc(WebServer **&arr, unsigned n)
{
	for (unsigned i = 0; i < n; ++i)
		delete arr[i];
	delete[] arr;
	arr = nullptr;
}

void ServerFarm::copy(const ServerFarm &sF)
{
	if (servers)
		dealloc(servers, count);
	if (name)
		delete[] name;
	WebServer **newArr = new (std::nothrow) WebServer *[sF.count];
	if (!newArr)
		return;
	for (unsigned i = 0; i < sF.count; ++i)
	{
		newArr[i] = new (std::nothrow) WebServer(*sF.servers[i]);
		if (!newArr[i])
		{
			dealloc(newArr, i);
			return;
		}
	}

	char *newName = new (std::nothrow) char[strlen(sF.name) + 1];
	if (!newName)
	{
		dealloc(newArr, sF.count);
		return;
	}
	strcpy(newName, sF.name);
	name = newName;
	servers = newArr;
	count = sF.count;
}

ServerFarm::ServerFarm()
{
	servers = nullptr;
	name = nullptr;
	count = 0;
	std::cout << "<ServerFarm created successfully.>\n";
}

ServerFarm::ServerFarm(const ServerFarm &sF)
{
	servers = nullptr;
	name = nullptr;
	copy(sF);
	std::cout << "<ServerFarm created successfully.>\n";
}

const ServerFarm &ServerFarm::operator=(const ServerFarm &sF)
{
	if (this != &sF)
		copy(sF);
	return *this;
}

void ServerFarm::print() const
{
	std::cout << "Name: " << (name ? name : "No name") << '\n';
	for (unsigned i = 0; i < count; ++i)
	{
		std::cout << '\t' << i + 1 << ": ";
		servers[i]->print();
	}
}

ServerFarm::~ServerFarm()
{
	dealloc(servers, count);
	if (name)
		delete[] name;
	std::cout << "<ServerFarm deleted successfully.>\n";
}

ServerFarm &ServerFarm::addServer(const WebServer &wS)
{
	WebServer **newArr = new (std::nothrow) WebServer *[count + 1];
	if (!newArr)
	{
		std::cout << "<WebServer could not be added.>\n";
		return *this;
	}
	unsigned i = 0;
	while (i < count && *servers[i] < wS)
	{
		newArr[i] = servers[i];
		++i;
	}
	newArr[i++] = new (std::nothrow) WebServer(wS);
	if (!newArr[i - 1])
	{
		delete[] newArr;
		return *this;
	}
	while (i <= count)
	{
		newArr[i] = servers[i - 1];
		++i;
	}
	++count;
	delete[] servers;
	servers = newArr;
	std::cout << "<WebServer added succesfully.>\n";
	return *this;
}

ServerFarm &ServerFarm::operator-=(const char *ip)
{
	unsigned i = 0;
	char buf[BUF_MAX];
	while (i < count && strcmp(servers[i]->IPtoString(buf), ip))
		++i;
	if (i == count)
	{
		std::cout << "<WebServer not found in ServerFarm.>\n";
		return *this;
	}
	delete servers[i];
	WebServer **newArr = new (std::nothrow) WebServer *[count - 1];
	if (!newArr)
	{
		std::cout << "<WebServer could not be removed.>\n";
		return *this;
	}
	for (unsigned j = 0; j < i; ++j)
		newArr[j] = servers[j];
	for (unsigned j = i; j < count - 1; ++j)
		newArr[j] = servers[j + 1];
	--count;
	delete[] servers;
	servers = newArr;
	std::cout << "<WebServer removed sucessfully.>\n";
	return *this;
}

unsigned ServerFarm::countInNetwork(const char *web) const
{
	unsigned res = 0;
	char buf[BUF_MAX];
	for (unsigned i = 0; i < IP_COUNT; ++i)
		res += !strcmp(servers[i]->webString(buf), web);
	return res;
}

void ServerFarm::findMaxNetwork() const
{
	char buf1[BUF_MAX], buf2[BUF_MAX];
	if (!count)
	{
		std::cout << "<No Networks.>\n";
		return;
	}
	unsigned maxIndex = 0, maxWebs = 0;
	unsigned countWebs, current = 0;
	do
	{
		countWebs = 1;

		while (current < count - 1 && !strcmp(servers[current]->webString(buf1), servers[current + 1]->webString(buf2)))
		{
			++countWebs;
			++current;
		}
		if (countWebs > maxWebs)
		{
			maxIndex = current;
			maxWebs = countWebs;
		}
		++current;
	} while (current < count - 1);
	servers[maxIndex]->webString(buf1);
	char *buf1End = buf1;
	while (*buf1End)
		++buf1End;
	*buf1End++ = '.';
	*buf1End++ = '0';
	*buf1End = '\0';
	std::cout << buf1 << '\n';
}

ServerFarm &ServerFarm::sort()
{
	unsigned iMin = 0;
	for (unsigned i = 0; i < count - 1; ++i)
	{
		iMin = i;
		for (unsigned j = i + 1; j < count; ++j)
			if (!(*servers[j] < *servers[iMin]))
				iMin = j;
		WebServer *tmp = servers[i];
		servers[i] = servers[iMin];
		servers[iMin] = tmp;
	}
	return *this;
}
