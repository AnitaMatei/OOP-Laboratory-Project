#include "Polynomial.hpp"


Polynomial::Polynomial(std::vector<double> coeff, int degree) {
	mCoeff = coeff;
	mDegree = degree;
}

Polynomial::Polynomial(const Polynomial& p) {
	mCoeff = p.mCoeff;
	mDegree = p.mDegree;
}


Polynomial& Polynomial::operator+=(const Polynomial& p) {
	
	for (int i = 0; i <= getSmallerDegree(*this,p); i++) {  //regardless of which polynom is bigger, it adds the 2 up until it stops at the smaller degree of the two
		mCoeff[i] += p.mCoeff[i];
	}

	if (mDegree < p.mDegree) {
		for (int i = mDegree+1; i <= p.mDegree; i++) {
			mCoeff.push_back(p.mCoeff[i]);
		}
		mDegree = p.mDegree;
	}

	return *this;
}

Polynomial& Polynomial::operator+=(const double& p) {  //adds up a 0 degree polynom, ex: (x^2+1) + (3) 
	mCoeff[0] += p;

	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& p) {
	Polynomial temp(p);

	for (int i = 0; i <= p.mDegree; i++) {
		temp.mCoeff[i] *= -1;
	}

	*this += temp;  //adding the opposite of the vector

	return *this;
}

Polynomial& Polynomial::operator-=(const double& p) {
	*this += (-p);
	
	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& p)
{
	std::vector<double> tempVector(mDegree + p.mDegree + 1, 0);
	Polynomial temp(tempVector,mDegree+p.mDegree);

	for (int i = 0; i <= mDegree; i++) {
		for (int j = 0; j <= p.mDegree; j++) {
			temp.mCoeff[i+j] += mCoeff[i] * p.mCoeff[j];
		}
	}
	*this = temp;
	
	return *this;
}

Polynomial& Polynomial::operator*=(const double& p)
{
	for (int i = 0; i <= mDegree; i++) {
		mCoeff[i] *= p;
	}

	return *this;
}

Polynomial& Polynomial::operator/=(const Polynomial& p)
{
	if (mDegree < p.mDegree) {
		Polynomial temp({ 0 }, 0);
		*this = temp;
	}
	else {
		Polynomial remainder(p);
		std::vector<double> quotientCoeff(mDegree-p.mDegree,0);
		Polynomial quotient(quotientCoeff, mDegree-p.mDegree);

		while (remainder.mDegree > p.mDegree) {

			int i;
			for (i = remainder.mDegree; remainder.mCoeff[i] == 0; i--) {

			}
			quotient.mCoeff[i - p.mDegree] = remainder.mCoeff[i] / p.mCoeff[p.mDegree];

		}
	}


	return *this;
}

Polynomial Polynomial::operator + () {
	return *this;
}

Polynomial Polynomial::operator-() {
	for (int i = 0; i <= mDegree; i++)
		mCoeff[i] *= -1;
	
	return *this;
}

Polynomial Polynomial::operator+(const Polynomial p) {
	Polynomial temp(*this);
	temp += p;

	return temp;
}

Polynomial Polynomial::operator+(const double& p) {
	Polynomial temp(*this);
	temp += p;

	return temp;
}

Polynomial operator+(const double& p, const Polynomial& p2) {
	Polynomial temp(p2);
	temp += p;

	return temp;
}

Polynomial Polynomial::operator-(const Polynomial p) {
	Polynomial temp(*this);
	temp -= p;

	return temp;
}

Polynomial Polynomial::operator-(const double& p) {
	Polynomial temp(*this);
	temp -= p;

	return temp;
}

Polynomial operator-(const double& p, const Polynomial& p2) {
	Polynomial temp({ p },0);							//in deduction order matters so the temp polynomial is initiated with the double, from which we deduct  the polynomial object
	temp -= p2;

	return temp;
}

Polynomial Polynomial::operator*(const Polynomial p) {
	Polynomial temp(*this);
	temp *= p;

	return temp;
}

Polynomial Polynomial::operator*(const double& p) {
	Polynomial temp(*this);
	temp *= p;

	return temp;
}

Polynomial operator*(const double& p, const Polynomial& p2) {
	Polynomial temp(p2);
	temp *= p;

	return temp;
}

Polynomial Polynomial::operator^(const int& power) {
	Polynomial temp(*this);					//we return a copy so that we do p^2 rather the p=p^2

	for (int i = 1; i < power; i++) {
		temp *= *this;
	}
	return temp;
}

double Polynomial::operator()(const int& value) {
	double temp=0.0;
	for (int i = 0; i <= mDegree; i++) {
		temp += mCoeff[i] * pow(value, i);
	}
	return temp;
}

double& Polynomial::operator[](const int& index) {
	return mCoeff[index];
}

bool Polynomial::operator==(const Polynomial& p) {
	return !(*this != p);
}


bool Polynomial::operator==(const double& p) {
	return !(*this!=p);
}

bool operator==(const double& p, const Polynomial& p2) {
	return !(p!=p2);
}

bool Polynomial::operator!=(const Polynomial& p) {
	if (mDegree != p.mDegree)
		return 1;
	for (int i = 0; i <= mDegree; i++) {
		if (mCoeff[i] != p.mCoeff[i])
			return 1;
	}
	return 0;
}

bool Polynomial::operator!=(const double& p) {
	if (mDegree > 0)
		return 1;

	return mCoeff[0] != p;
}

bool operator!=(const double& p, const Polynomial& p2) {
	if (p2.mDegree > 0)
		return 1;

	return p != p2.mCoeff[0];
}

std::istream& operator>>(std::istream& in, Polynomial& p) {
	in >> p.mDegree;
	for (int i = 0; i <= p.mDegree; i++) {
		double q;
		in >> q;
		p.mCoeff.push_back(q);
	}
	return in;
}

std::ifstream& operator>>(std::ifstream& fin, Polynomial& p) {
	fin >> p.mDegree;
	for (int i = 0; i <= p.mDegree; i++) {
		double q;
		fin >> q;
		p.mCoeff.push_back(q);
	}
	return fin;
}

std::ostream & operator<<(std::ostream & out, const Polynomial & p)
{ 
	for (int i = 0; i <= p.mDegree; i++) {

		if (p.mCoeff[i] > 0)
			out << "+";
		else out << "-";

		out << p.mCoeff[i] << "x^" << i;
		
	}
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& fout, const Polynomial& p) {
	for (int i = 0; i <= p.mDegree; i++) {
		
		if (p.mCoeff[i] > 0)
			fout << "+";
		else fout << "-";

		fout << p.mCoeff[i] << "x^" << i;

	}
	fout << std::endl;
	return fout;
}

int Polynomial::getDegree() {
	return mDegree;
}

int Polynomial::getSmallerDegree(const Polynomial& p, const Polynomial& p2) {
	return (p.mDegree < p2.mDegree ? p.mDegree : p2.mDegree);
}