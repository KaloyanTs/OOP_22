#include <iostream>
#include <fstream>

int main()
{
	std::ifstream i;
	std::ofstream o;
	o.open("week_7_files.txt");
	//			std::ios::app
	if (o)
	{
		//o.seekp(std::ios::end);
		o << "12345yryryryryr56";
	}
	o.close();
	i.open("week_7_files.txt");
	unsigned x;
	i.seekg(2, std::ios::cur);
	i >> x;
	std::cout << x << ' ';
	i.seekg(-2, std::ios::end);
	std::cout << i.tellg() << '\n';
	i >> x;
	std::cout << x << '\n';
	i.close();

	o.open("week_7_files.txt");
	//			std::ios::app
	if (o)
	{
		//o.seekp(std::ios::end);
		o << "La la la la la\nLa la la la\nLa la la la la laa";
	}
	o.close();

	i.open("week_7_files.txt");
	unsigned length;
	i.seekg(0, std::ios::end);
	length = i.tellg();
	std::cout << "Length: " << length << '\n';
	char *buffer = new char[length + 1];
	unsigned iter = 0;
	i.seekg(0, std::ios::beg);
	i.read(buffer, length);
	/*while (!i.eof())
		i.get(buffer[iter++]);					???????????
	buffer[iter] = '\0';*/
	std::cout << buffer << "\n\n";
	i.seekg(2, std::ios::cur);
	i >> x;
	std::cout << x << ' ';
	i.seekg(-2, std::ios::end);
	std::cout << i.tellg() << '\n';
	i >> x;
	std::cout << x;
	i.close();

	return 0;
}