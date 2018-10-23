#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>

class Polynomial {

public:

	Polynomial(std::vector<double> = {}, int = 0);
	Polynomial(Polynomial&);

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

	Polynomial operator+(const Polynomial); //without address to keep a chain going, ie Polynomial a=b+c+d
	Polynomial operator+(const double&);
	friend Polynomial operator+(const double&, const Polynomial); //friend function defined outside the class so we can do <double>+<Polynomial>

	Polynomial operator-(const Polynomial);
	Polynomial operator-(const double&);
	friend Polynomial operator-(const double&, const Polynomial);

	Polynomial operator*(const Polynomial);
	Polynomial operator*(const double&);
	friend Polynomial operator*(const double&, const Polynomial);

	Polynomial operator/(const Polynomial);
	Polynomial operator/(const int&);
	friend Polynomial operator/(const double&, const Polynomial);

	Polynomial operator^(const int&);

	double operator()(const int&);
	double& operator[](const int&);

	bool operator==(const Polynomial&);
	bool operator==(const double&);
	friend bool operator==(const double&, const Polynomial&);

	bool operator!=(const Polynomial&);
	bool operator!=(const double&);
	friend bool operator!=(const double&, const Polynomial&);

	friend std::istream& operator>>(std::istream&, const Polynomial&); //friend so that i can call cin>>p1 rather than p1>>cin
	friend std::ifstream& operator>>(std::ifstream&, const Polynomial&); //friend so that i can call cin>>p1 rather than p1>>cin

	friend std::ostream& operator<<(std::ostream&, const Polynomial&);
	friend std::ofstream& operator<<(std::ofstream&, const Polynomial&);

	int getDegree();



private:
	std::vector<double> mCoef; //the vector of coefficients
	int mDegree; //degree of the polynomial





};



#endif //POLYNOMIAL_H_