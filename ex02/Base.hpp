#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdint>
#include <random>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif