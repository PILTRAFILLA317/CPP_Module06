#include "Base.hpp"

Base *generate(void) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribucion(1, 3);
	int numeroAleatorio = distribucion(gen);
	if (numeroAleatorio == 1) {
		std::cout << "A" << std::endl;
		return new A;
	} else if (numeroAleatorio == 2) {
		std::cout << "B" << std::endl;
		return new B;
	} else {
		std::cout << "C" << std::endl;
		return new C;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Error" << std::endl;
	}
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (std::bad_cast &bc) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;
		} catch (std::bad_cast &bc) {
			try {
				C &c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)c;
			} catch (std::bad_cast &bc) {
				std::cout << "Error" << std::endl;
			}
		}
	}
}