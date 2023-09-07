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
		std::string _input;
		int _type;
	public:
		Converter(std::string input);
		Converter(Converter const &other);
		~Converter();
		Converter &operator=(Converter const &other);
	
		void convert();
		void printChar();
		void printInt();
		void printFloat();
		void printDouble();
	};

#endif