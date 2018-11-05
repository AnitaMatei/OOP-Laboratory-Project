#include <iostream>
#include "Polynomial.hpp"
#include <string>

int main() {

	Polynomial p({ -4, 0, -2, 1 },3), p2({ -3, 1, 0, 1 }, 3);

	std::cin >> p;

	
	std::cout << p;

	system("pause");
	return 0;
}