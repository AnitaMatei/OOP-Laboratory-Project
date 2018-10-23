#include <iostream>
#include "Polynomial.hpp"

int main() {

	Polynomial p({ 1, 1, 1 },2), p2({ 1,1,1 }, 2);

	std::cout << (p^2);
	p = -p2+2.0+p2+p2;
	std::cout << p;

	system("pause");
	return 0;
}