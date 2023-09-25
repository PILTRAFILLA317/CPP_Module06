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

class Serial
{
	private:
		Serial();
		Serial(Serial const &other);
		Serial &operator=(Serial const &other);
		~Serial();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif