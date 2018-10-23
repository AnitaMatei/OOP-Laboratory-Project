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
	
	for (int i = 0; i <= (mDegree < p.mDegree ? mDegree : p.mDegree); i++) {  //regardless of which polynom is bigger, it adds the 2 up until it stops at the smaller degree of the two
		mCoeff[i] += p.mCoeff[i];
	}

	if (mDegree < p.mDegree) {
		for (int i = mDegree; i <= p.mDegree; i++) {
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