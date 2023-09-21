#include "Converter.hpp"

Converter::Converter(std::string input) : _input(input), _type(0) {}

Converter::Converter(Converter const &other) : _input(other._input), _type(other._type) {}

Converter::~Converter() {}

Converter &Converter::operator=(Converter const &other) {
	if (this != &other){
		this->_input = other._input;
		this->_type = other._type;
	}
	return *this;
}

void Converter::convert() {
	if (this->_input.length() == 1 && !isdigit(this->_input[0]))
		this->_type = CHAR;
	else if (this->_input == "-inff" || this->_input == "+inff" || this->_input == "nanf")
		this->_type = FLOAT;
	else if (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan")
		this->_type = DOUBLE;
	else if (this->_input.length() > 1 && this->_input[this->_input.length() - 1] == 'f')
		this->_type = FLOAT;
	else
		this->_type = DOUBLE;
}

void Converter::printChar() {
	std::cout << "char: ";
	if (this->_type == CHAR){
		if (this->_input[0] < 32 || this->_input[0] > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << this->_input[0] << "'" << std::endl;
	}
	else if (this->_type == INT){
		if (this->_input[0] < 32 || this->_input[0] > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(std::stoi(this->_input)) << "'" << std::endl;
	}
	else if (this->_type == FLOAT){
		if (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan")
			std::cout << "impossible" << std::endl;
		else if (std::stoi(this->_input) < 32 || std::stoi(this->_input) > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(std::stof(this->_input)) << "'" << std::endl;
	}
	else if (this->_type == DOUBLE){
		if (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan")
			std::cout << "impossible" << std::endl;
		else if (std::stoi(this->_input) < 32 || std::stoi(this->_input) > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(std::stod(this->_input)) << "'" << std::endl;
	}
}

void Converter::printInt() {
	std::cout << "int: ";
	if (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan")
		std::cout << "impossible" << std::endl;
	else
	if (this->_type == CHAR)
		std::cout << static_cast<int>(this->_input[0]) << std::endl;
	else if (this->_type == INT)
		std::cout << std::stoi(this->_input) << std::endl;
	else if (this->_type == FLOAT)
		std::cout << static_cast<int>(std::stof(this->_input)) << std::endl;
	else if (this->_type == DOUBLE)
		std::cout << static_cast<int>(std::stod(this->_input)) << std::endl;
}

void Converter::printFloat() {
	std::cout << "float: ";
	if (this->_input == "-inff" || this->_input == "+inff" || this->_input == "nanf")
		std::cout << this->_input << std::endl;
	else if (this->_type == CHAR)
		std::cout << static_cast<float>(this->_input[0]) << "f" << std::endl;
	else if (this->_type == INT)
		std::cout << static_cast<float>(std::stoi(this->_input)) << "f" << std::endl;
	else if (this->_type == FLOAT)
		std::cout << std::stof(this->_input) << "f" << std::endl;
	else if (this->_type == DOUBLE)
		std::cout << static_cast<float>(std::stod(this->_input)) << "f" << std::endl;
}

void Converter::printDouble() {
	std::cout << "double: ";
	if (this->_input == "-inf" || this->_input == "+inf" || this->_input == "nan")
		std::cout << this->_input << std::endl;
	else if (this->_type == CHAR)
		std::cout << static_cast<double>(this->_input[0]) << std::endl;
	else if (this->_type == INT)
		std::cout << static_cast<double>(std::stoi(this->_input)) << std::endl;
	else if (this->_type == FLOAT)
		std::cout << static_cast<double>(std::stof(this->_input)) << std::endl;
	else if (this->_type == DOUBLE)
		std::cout << std::stod(this->_input) << std::endl;
}
