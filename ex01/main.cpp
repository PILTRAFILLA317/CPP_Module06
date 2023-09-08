#include "Serial.hpp"

int main()
{
	Data *d = new Data;
	d->str = "Jose Vaca";
	d->n = 69;
	std::cout << "Data before serialization:" << std::endl;
	std::cout << "str: " << d->str << std::endl;
	std::cout << "n: " << d->n << std::endl;
	uintptr_t p = serialize(d);
	Data *d2 = deserialize(p);
	std::cout << "Data after deserialization:" << std::endl;
	std::cout << "str: " << d2->str << std::endl;
	std::cout << "n: " << d2->n << std::endl;
	delete d;
	return 0;
}