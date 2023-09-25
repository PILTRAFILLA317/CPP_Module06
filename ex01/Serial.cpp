#include "Serial.hpp"

Serial::Serial(){}

Serial::Serial(Serial const &other){
	*this = other;
}

Serial &Serial::operator=(Serial const &other){
	(void)other;
	return *this;
}

Serial::~Serial(){}

uintptr_t Serial::serialize(Data *ptr){
	uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
	return p;
}

Data *Serial::deserialize(uintptr_t raw){
	Data *d = reinterpret_cast<Data *>(raw);
	return d;
}