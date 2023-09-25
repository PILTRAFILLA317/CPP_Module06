#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>

enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class Converter
{
	private:
		Converter();
		Converter(Converter const &other);
		Converter &operator=(Converter const &other);
		~Converter();
	public:
		static int convert(std::string s);
		static void printChar(std::string s, int type);
		static void printInt(std::string s, int type);
		static void printFloat(std::string s, int type);
		static void printDouble(std::string s, int type);
	};

#endif