#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Polynomial {
public:

	Polynomial(std::vector<double> = {0}, int = 0);   //the default polynomial is 0
	Polynomial(const Polynomial&);

	~Polynomial() {}

	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator+=(const double&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator-=(const double&);
	Polynomial& operator*=(const Polynomial&);
	Polynomial& operator*=(const double&);
	Polynomial& operator/=(const Polynomial&);
	Polynomial& operator/=(const double&);
	Polynomial& operator%=(const Polynomial&);
	Polynomial& operator%=(const double&);

	Polynomial operator+();
	Polynomial operator-();

	Polynomial operator+(const Polynomial); //without reference to keep a chain going, ie Polynomial a=b+c+d
	Polynomial operator+(const double&);
	friend Polynomial operator+(const double&, const Polynomial); //friend function defined outside the class so we can do <double>+<Polynomial>

	Polynomial operator-(const Polynomial);
	Polynomial operator-(const double&);
	friend Polynomial operator-(const double&, const Polynomial);

	Polynomial operator*(const Polynomial);
	Polynomial operator*(const double&);
	friend Polynomial operator*(const double&, const Polynomial);

	Polynomial operator/(const Polynomial);
	Polynomial operator/(const double&);
	friend Polynomial operator/(const double&, const Polynomial);

	Polynomial operator%(const Polynomial);
	Polynomial operator%(const double&);
	friend Polynomial operator%(const double&, const Polynomial);

	Polynomial operator^(const int&);

	double operator()(const int&);
	double& operator[](const int&);

	bool operator==(const Polynomial&);
	bool operator==(const double&);
	friend bool operator==(const double&, const Polynomial&);

	bool operator!=(const Polynomial&);
	bool operator!=(const double&);
	friend bool operator!=(const double&, const Polynomial&);

	friend std::istream& operator>>(std::istream&, Polynomial&); //friend so that i can call cin>>p1 rather than p1>>cin
	friend std::ifstream& operator>>(std::ifstream&, Polynomial&); //friend so that i can call cin>>p1 rather than p1>>cin

	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	friend std::ofstream& operator<<(std::ofstream&, const Polynomial&);

	std::string toString();

	int getDegree();
	static int getSmallerDegree(const Polynomial&, const Polynomial&);	//returns the smaller degree of 2 polynomials

private:
	static Polynomial divide(const Polynomial&, const Polynomial&, const bool); //separate function for division so i can use it for both remainder and quotient

	std::vector<double> mCoeff; //the vector of coefficients
	int mDegree; //degree of the polynomial


};



#endif //POLYNOMIAL_H_