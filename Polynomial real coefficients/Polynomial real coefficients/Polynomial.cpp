#include "Polynomial.hpp"


Polynomial::Polynomial(const std::vector<double> coeff, const int degree) {
	mCoeff = coeff;
	mDegree = degree;
}

Polynomial::Polynomial(const Polynomial& p) {
	mCoeff = p.mCoeff;
	mDegree = p.mDegree;
}


Polynomial& Polynomial::operator+=(const Polynomial& p) {

	for (int i = 0; i <= getSmallerDegree(*this, p); i++) {  //regardless of which polynom is bigger, it adds the 2 up until it stops at the smaller degree of the two
		mCoeff[i] += p.mCoeff[i];
	}

	if (mDegree < p.mDegree) {
		for (int i = mDegree + 1; i <= p.mDegree; i++) {
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
	for (int i = mDegree; i >= 0; i--) {
		if (mCoeff[i] != 0)
			break;
		else {
			mDegree--;
			mCoeff.erase(mCoeff.begin() + i);
		}
	}

	return *this;
}

Polynomial& Polynomial::operator-=(const double& p) {
	*this += (-p);

	return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& p)
{
	std::vector<double> tempVector(mDegree + p.mDegree + 1, 0);
	Polynomial temp(tempVector, mDegree + p.mDegree);

	for (int i = 0; i <= mDegree; i++) {
		for (int j = 0; j <= p.mDegree; j++) {
			temp.mCoeff[i + j] += mCoeff[i] * p.mCoeff[j];
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
	*this = divide(*this, p, true);
	return *this;
}

Polynomial & Polynomial::operator/=(const double &p)
{
	for (int i = 0; i <= mDegree; i++)
		mCoeff[i] /= p;
	return *this;

}

Polynomial & Polynomial::operator%=(const Polynomial &p)
{
	*this = divide(*this, p, false);
	return *this;
}

Polynomial & Polynomial::operator%=(const double &p)
{
	Polynomial temp({ 0 }, 0);
	return temp;
}

Polynomial Polynomial::operator+() {
	return *this;
}

Polynomial Polynomial::operator-() {
	Polynomial temp(*this);
	for (int i = 0; i <= mDegree; i++)
		temp.mCoeff[i] *= -1;

	return temp;
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

Polynomial operator+(const double& p, const Polynomial p2) {
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

Polynomial operator-(const double& p, const Polynomial p2) {
	Polynomial temp({ p }, 0);							//in deduction order matters so the temp polynomial is initiated with the double, from which we deduct  the polynomial object
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

Polynomial Polynomial::operator/(const Polynomial p)
{
	Polynomial temp(*this);
	temp /= p;
	return temp;
}

Polynomial Polynomial::operator/(const double &p)
{
	Polynomial temp(*this);
	temp /= p;
	return temp;
}

Polynomial Polynomial::operator%(const Polynomial p)
{
	Polynomial temp(*this);
	temp %= p;
	return temp;
}

Polynomial Polynomial::operator%(const double & p)
{
	Polynomial temp(*this);
	temp %= p;
	return temp;
}

Polynomial operator*(const double& p, const Polynomial p2) {
	Polynomial temp(p2);
	temp *= p;

	return temp;
}

Polynomial operator/(const double &p, const Polynomial p2)
{
	Polynomial temp({ p }, 0), temp2(p2);
	return Polynomial::divide(temp, temp2, true);
}

Polynomial operator%(const double &p, const Polynomial p2)
{
	Polynomial temp({ p }, 0), temp2(p2);
	return Polynomial::divide(temp, temp2, false);
}

Polynomial Polynomial::operator^(const int& power) {
	Polynomial temp(*this);					//we return a copy so that we do p^2 rather the p=p^2

	for (int i = 1; i < power; i++) {
		temp *= *this;
	}
	return temp;
}

double Polynomial::operator()(const int& value) {
	double temp = 0.0;
	for (int i = 0; i <= mDegree; i++) {
		temp += mCoeff[i] * pow(value, i);
	}
	return temp;
}

double& Polynomial::operator[](const int& index) {
	if (index > mDegree)
		return mCoeff[mDegree];
	else
		return mCoeff[index];
}

bool Polynomial::operator==(const Polynomial& p) {
	return !(*this != p);
}


bool Polynomial::operator==(const double& p) {
	return !(*this != p);
}

bool operator==(const double& p, const Polynomial& p2) {
	return !(p != p2);
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

	std::string tbr;
	Polynomial temp;
	in >> tbr;
	int i;

	for (i = 1; i < tbr.length(); i++) {			//we look for the monomial of degree 0, provided we have another one as well 
		if (tbr[i] == '+' || tbr[i] == '-') {
			char token = tbr[i];						//when and if its found we add it as the first coefficient
			std::string tempStr = tbr.substr(0, tbr.find(token));
			temp.mCoeff[0] = (atof(tempStr.c_str()));
			tbr.erase(0, tempStr.length());
			break;
		}
		else if (tbr[i] == '*')
			break;
	}

	if (tbr.length() != 0 && tbr.find('*') == -1) {		//if we have only a monomial of degree 0
		temp.mCoeff[0] = atof(tbr.c_str());
		tbr.erase(0, tbr.length());
	}

	while (tbr.length() > 0) {										//here we search for the monomials of degree 1 or higher
		std::string tempStr = tbr.substr(0, tbr.find("*x"));
		if (tbr[tempStr.length() + 2] != '^') {					//if we have a monomial of degree 1 (ie we dont have ^n after *x)
			temp.mCoeff.push_back(atof(tempStr.c_str()));
			tbr.erase(0, tempStr.length() + 2);
		}
		else {														//the normal loop for monomials of degree i>1
			std::string tempTbr = tbr;			//we delete the sign of the current coefficient so that it doesnt trick us when searching
			tempTbr.erase(0, 1);
			std::string degreeString;						//the string that holds the string of the value of the degree
			if (tempTbr.find("+") == -1 && tempTbr.find("-") == -1) {			//if we dont find another monomial we go with what we have left as the degree of the current monomial
				degreeString = tbr.substr(tempStr.length() + 3, -1);
			}
			else {
				int tokenPos = tempTbr.find("+") < tempTbr.find("-") ? tempTbr.find("+") : tempTbr.find("-");		//the position of the next sign, be it - or +
				degreeString = tbr.substr(tempStr.length() + 3, tokenPos - 3);
			}

			int x = atof(degreeString.c_str());
			for (int i = temp.mCoeff.size(); i < x; i++) {
				temp.mCoeff.push_back(0);						//if we jump from degree 3 to degree i>4, we have to push back some values of 0
			}
			temp.mCoeff.push_back(atof(tempStr.c_str()));
			tbr.erase(0, tempStr.length() + degreeString.length() + 3);			//keep deleting from the string you read
		}
	}
	temp.mDegree = temp.mCoeff.size() - 1;
	p = temp;

	return in;
}

std::ifstream& operator>>(std::ifstream& fin, Polynomial& p) {

	std::string tbr;
	Polynomial temp;
	fin >> tbr;
	int i;

	for (i = 1; i < tbr.length(); i++) {
		if (tbr[i] == '+' || tbr[i] == '-') {
			char token = tbr[i];
			std::string tempStr = tbr.substr(0, tbr.find(token));
			temp.mCoeff[0] = (atof(tempStr.c_str()));
			tbr.erase(0, tempStr.length());
			break;
		}
		else if (tbr[i] == '*')
			break;
	}

	if (tbr.length() != 0 && tbr.find('*') == -1) {
		temp.mCoeff[0] = atof(tbr.c_str());
		tbr.erase(0, tbr.length());
	}

	while (tbr.length() > 0) {
		std::string tempStr = tbr.substr(0, tbr.find("*x"));
		if (tbr[tempStr.length() + 2] != '^') {
			temp.mCoeff.push_back(atof(tempStr.c_str()));
			tbr.erase(0, tempStr.length() + 2);
		}
		else {
			std::string tempTbr = tbr;
			tempTbr.erase(0, 1);
			std::string degreeString;
			if (tempTbr.find("+") == -1 && tempTbr.find("-") == -1) {
				degreeString = tbr.substr(tempStr.length() + 3, -1);
			}
			else {
				int tokenPos = tempTbr.find("+") < tempTbr.find("-") ? tempTbr.find("+") : tempTbr.find("-");
				degreeString = tbr.substr(tempStr.length() + 3, tokenPos - 3);
			}

			int x = atof(degreeString.c_str());
			for (int i = temp.mCoeff.size(); i < x; i++) {
				temp.mCoeff.push_back(0);
			}
			temp.mCoeff.push_back(atof(tempStr.c_str()));
			tbr.erase(0, tempStr.length() + degreeString.length() + 3);
		}
	}
	temp.mDegree = temp.mCoeff.size() - 1;
	p = temp;

	return fin;
}

std::ostream & operator<<(std::ostream & out, const Polynomial & p)
{
	if (p.mCoeff[0] != 0)
	{
		if (p.mCoeff[0] > 0)
			out << "+";
		out << p.mCoeff[0];
	}
	for (int i = 1; i <= p.mDegree; i++) {
		if (p.mCoeff[i] != 0) {
			if (p.mCoeff[i] > 0)
				out << "+";

			out << p.mCoeff[i] << "*x";
			if (i > 1)
				out << "^" << i;
		}
	}
	out << std::endl;
	return out;
}

std::ofstream& operator<<(std::ofstream& fout, const Polynomial& p) {
	if (p.mCoeff[0] != 0)
	{
		if (p.mCoeff[0] > 0)
			fout << "+";
		fout << p.mCoeff[0];
	}
	for (int i = 1; i <= p.mDegree; i++) {
		if (p.mCoeff[i] != 0) {
			if (p.mCoeff[i] > 0)
				fout << "+";

			fout << p.mCoeff[i] << "*x";
			if (i > 1)
				fout << "^" << i;
		}
	}
	fout << std::endl;
	return fout;
}

std::string Polynomial::toString()
{
	std::string temp = "";
	temp += std::to_string(mCoeff[0]);
	for (int i = 1; i <= mDegree; i++) {
		if (mCoeff[i] != 0) {
			if (mCoeff[i] > 0)
				temp += "+";

			temp += std::to_string(mCoeff[i]);
			temp += "*x^";
			temp += std::to_string(i);
		}
	}
	return temp;
}

int Polynomial::getDegree() {
	return mDegree;
}

int Polynomial::getSmallerDegree(const Polynomial& p, const Polynomial& p2) {
	return (p.mDegree < p2.mDegree ? p.mDegree : p2.mDegree);
}

Polynomial Polynomial::divide(const Polynomial &p, const Polynomial & p2, const bool wantQuotient)
{
	Polynomial returnPol({ 0 }, 0);  //in case we want the quotient we default the return value to the polynomial 0
	if (!wantQuotient)
		returnPol = p;

	if (p.mDegree >= p2.mDegree) {
		Polynomial quotient;
		Polynomial remainder(p);

		while (remainder.mDegree >= p2.mDegree) {
			std::vector<double> coeffTemp;
			for (int i = 0; i < remainder.mDegree - p2.mDegree; i++) {
				coeffTemp.push_back(0);
			}
			coeffTemp.push_back(remainder.mCoeff[remainder.mDegree] / p2.mCoeff[p2.mDegree]);
			Polynomial temp(coeffTemp, remainder.mDegree - p2.mDegree);

			quotient = quotient + temp;
			remainder = remainder - temp * p2;
		}
		if (wantQuotient)
			returnPol = quotient;
		else returnPol = remainder;
	}

	return returnPol;
}
