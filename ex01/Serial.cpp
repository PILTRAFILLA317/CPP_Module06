#include "Serial.hpp"

uintptr_t serialize(Data *ptr){
	uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
	return p;
}

Data *deserialize(uintptr_t raw){
	Data *d = reinterpret_cast<Data *>(raw);
	return d;
}