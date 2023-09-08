#ifndef SERIAL_HPP
#define SERIAL_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdint>

struct Data
{
	std::string str;
	int n;
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif