#include "Converter.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cout << "Usage: ./a.out <number>" << std::endl;
		return 1;
	}

	try{
		std::string s(av[1]);
		Converter::printChar(s, Converter::convert(s));
		Converter::printInt(s, Converter::convert(s));
		Converter::printFloat(s, Converter::convert(s));
		Converter::printDouble(s, Converter::convert(s));
	}
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}