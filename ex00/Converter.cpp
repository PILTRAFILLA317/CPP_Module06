#include "Converter.hpp"

Converter::Converter() {}

Converter::Converter(Converter const &other) {
	(void)other;
}

Converter::~Converter() {}

Converter &Converter::operator=(Converter const &other) {
	(void)other;
	return *this;
}

int Converter::convert(std::string s) {
	if (s.length() == 1 && !isdigit(s[0]))
		return CHAR;
	else if (s == "-inff" || s == "+inff" || s == "nanf")
		return FLOAT;
	else if (s == "-inf" || s == "+inf" || s == "nan")
		return DOUBLE;
	else if (s.length() > 1 && s[s.length() - 1] == 'f')
		return FLOAT;
	else
		return DOUBLE;
}

void Converter::printChar(std::string s, int type) {
	std::cout << "char: ";
	if (type == CHAR){
		if (s[0] < 32 || s[0] > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << s[0] << "'" << std::endl;
	}
	else if (type == INT){
		if (s[0] < 32 || s[0] > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(std::stoi(s)) << "'" << std::endl;
	}
	else if (type == FLOAT){
		if (s == "-inf" || s == "+inf" || s == "nan")
			std::cout << "impossible" << std::endl;
		else if (std::stoi(s) < 32 || std::stoi(s) > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(std::stof(s)) << "'" << std::endl;
	}
	else if (type == DOUBLE){
		if (s == "-inf" || s == "+inf" || s == "nan")
			std::cout << "impossible" << std::endl;
		else if (std::stoi(s) < 32 || std::stoi(s) > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(std::stod(s)) << "'" << std::endl;
	}
}

void Converter::printInt(std::string s, int type) {
	std::cout << "int: ";
	if (s == "-inf" || s == "+inf" || s == "nan")
		std::cout << "impossible" << std::endl;
	else
	if (type == CHAR)
		std::cout << static_cast<int>(s[0]) << std::endl;
	else if (type == INT)
		std::cout << std::stoi(s) << std::endl;
	else if (type == FLOAT)
		std::cout << static_cast<int>(std::stof(s)) << std::endl;
	else if (type == DOUBLE)
		std::cout << static_cast<int>(std::stod(s)) << std::endl;
}

void Converter::printFloat(std::string s, int type) {
	std::cout << "float: ";
	if (s == "-inff" || s == "+inff" || s == "nanf")
		std::cout << s << std::endl;
	else if (type == CHAR)
		std::cout << static_cast<float>(s[0]) << "f" << std::endl;
	else if (type == INT)
		std::cout << static_cast<float>(std::stoi(s)) << "f" << std::endl;
	else if (type == FLOAT)
		std::cout << std::stof(s) << "f" << std::endl;
	else if (type == DOUBLE)
		std::cout << static_cast<float>(std::stod(s)) << "f" << std::endl;
}

void Converter::printDouble(std::string s, int type) {
	std::cout << "double: ";
	if (s == "-inf" || s == "+inf" || s == "nan")
		std::cout << s << std::endl;
	else if (type == CHAR)
		std::cout << static_cast<double>(s[0]) << std::endl;
	else if (type == INT)
		std::cout << static_cast<double>(std::stoi(s)) << std::endl;
	else if (type == FLOAT)
		std::cout << static_cast<double>(std::stof(s)) << std::endl;
	else if (type == DOUBLE)
		std::cout << std::stod(s) << std::endl;
}
