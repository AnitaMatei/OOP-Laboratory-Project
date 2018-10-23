#include <iostream>
#include "Polynomial.hpp"

int main() {

	Polynomial p({ 1,2,3 },2), p2({ 1,2,3 }, 2);

	p += p2;

	system("pause");
	return 0;
}