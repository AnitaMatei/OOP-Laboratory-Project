#include <iostream>
#include "Polynomial.hpp"
#include <string>

int main() {

	Polynomial p({ -4, 0, -2, 1 },3), p2({ -3, 1, 0, 1 }, 3);

	Polynomial p3;

	p3 = p + (-p2);

	
	std::cout << p<<p2<<p3;

	system("pause");
	return 0;
}