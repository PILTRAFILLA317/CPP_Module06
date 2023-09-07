#include "Converter.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cout << "Usage: ./a.out <number>" << std::endl;
		return 1;
	}

	try{
		Converter converter(av[1]);
		converter.convert();
		converter.printChar();
		converter.printInt();
		converter.printFloat();
		converter.printDouble();
	}
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}