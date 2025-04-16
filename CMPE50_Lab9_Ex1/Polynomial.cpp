/*
 * Polynomial.cpp
 *
 *  Created on: Oct 24, 2013
 *      Author: cltarng
 */


#include <iostream>
#include <cmath>
#include "polynomial.h"
using namespace std;


Polynomial::Polynomial()
{
	degree = 10;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(int degr)
{
	degree = degr;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(const Polynomial &poly)
{
	degree = poly.get_degree();
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = poly.get_coeff(i);
	}
}

Polynomial::Polynomial(double cf[], int deg)
{
	degree = deg;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = cf[i];
	}
}

Polynomial::~Polynomial()
{
	delete [] coeff;
}

int Polynomial::get_degree() const
{
	return degree;
}

double Polynomial::get_coeff(int deg) const
{
	if (degree < deg)
	{
		return 0;
		// The input degree is larger than the polynomial degree
	}
	return coeff[deg];
}

void Polynomial::set_coeff(int degr, double val)
{
	if (degree < degr)
	{
		cout << "Degree exceeded." << endl;
		return;
	}
	coeff[degr] = val;
}

// Evaluate the polynomial
double Polynomial::evaluate(double val)
{
	double result = 0.0;
	for (int i = 0; i <= degree; i++) {
		result += pow(val,i)*coeff[i];
	}
	return result;
}

// Assignment operator
void Polynomial::operator =(const Polynomial &poly)
{
	if (this == &poly)
	{
		// Copy to itself. Nothing to be done.
		return;
	}

	degree = poly.get_degree();
	delete [] coeff;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++) {
		coeff[i] = poly.get_coeff(i);
	}
}

// Overloaded operator +
Polynomial operator+(const Polynomial &pola, const Polynomial &polb)
{
	Polynomial highPol, lowPol;
	highPol = pola.degree >= polb.degree ? pola : polb;
	lowPol = pola.degree < polb.degree ? pola : polb;

	int degree = highPol.get_degree();
	double coeff[degree+1];

	for (int i = 0; i <= highPol.get_degree(); i++) {
		coeff[i] = highPol.get_coeff(i);
	}
	for (int i = 0; i <= lowPol.get_degree(); i++) {
		coeff[i] += lowPol.get_coeff(i);
	}

	int i;
	for (i = degree; i >= 0 && coeff[i] == 0; i--) {}
	degree = i;

	return Polynomial(coeff, degree);
}

// Overloaded operator -
Polynomial operator-(const Polynomial &pola, const Polynomial &polb)
{
	Polynomial highPol, lowPol;
	highPol = pola.degree >= polb.degree ? pola : polb;
	lowPol = pola.degree < polb.degree ? pola : polb;

	int degree = highPol.get_degree();
	double coeff[degree+1];

	if (highPol == pola) {
		for (int i = 0; i <= highPol.get_degree(); i++) {
			coeff[i] = highPol.get_coeff(i);
		}
	} else {
		for (int i = 0; i <= highPol.get_degree(); i++) {
			coeff[i] = -highPol.get_coeff(i);
		}
	}
	for (int i = 0; i <= lowPol.get_degree(); i++) {
		coeff[i] = pola.get_coeff(i) - polb.get_coeff(i);
	}

	int i;
	for (i = degree; i >= 0 && coeff[i] == 0; i--) {}
	degree = i;

	return Polynomial(coeff, degree);
}

// Overloaded operator +
Polynomial operator*(const Polynomial &pola, const Polynomial &polb)
{
	int degree = pola.get_degree() * polb.get_degree();
	double *coeff = new double[degree+1];
	Polynomial result;

	for (int i = 0; i <= pola.degree; i++) {
		degree = i + polb.degree;
		delete [] coeff;
		coeff = new double[degree+1];
		for (int j = 0; j <= polb.degree; j++) {
			coeff[i+j] = pola.get_coeff(i) * polb.get_coeff(j);
		}
		result = result + Polynomial(coeff, degree);
	}

	degree = result.get_degree();
	delete [] coeff;
	double coeff2[degree+1];

	for (int i = 0; i <= degree; i++) {
		coeff2[i] = result.get_coeff(i);
	}

	int i;
	for (i = degree; i >= 0 && coeff2[i] == 0; i--) {}
	degree = i;

	return Polynomial(coeff2, degree);
}

// Overloaded << operator
ostream& operator << (ostream& ost, const Polynomial &pol)
{
	if (pol.get_coeff(pol.degree) < 0) ost << "-";
	for (int i = pol.degree; i >= 0; i-- ){
		if ( pol.get_coeff(i) != 0 ) {
			if (i != pol.degree && pol.get_coeff(i) > 0) ost << " + ";
			else if (i != pol.degree) ost << " - ";
			if (i != 0) ost << fabs(pol.get_coeff(i)) << "x^" << i;
			else ost << fabs(pol.get_coeff(i));
		}
	}
	return ost;
}

Polynomial operator+(const Polynomial &polya, double c) {
	double co[1] = {c};
	Polynomial poly(co, 0);
	return poly + polya;
}

Polynomial operator+( double c, const Polynomial &polya) {
	return polya + c;
}

Polynomial operator-(const Polynomial &polya, double c) {
	double co[1] = {c};
	Polynomial poly(co, 0);
	return polya - poly;
}

Polynomial operator-( double c, const Polynomial &polya) {
	double co[1] = {c};
	Polynomial poly(co, 0);
	return poly - polya;
}

Polynomial operator*(const Polynomial &polya, double c) {
	double co[1] = {c};
	Polynomial poly(co, 0);
	return poly * polya;
}

Polynomial operator*( double c, const Polynomial &polya) {
	return polya * c;
}

bool operator==(const Polynomial &polya, const Polynomial &polyb) {
	if (polya.degree != polyb.degree) return false;
	for (int i = 0; i <= polya.degree; i++) {
		if (polya.get_coeff(i) != polyb.get_coeff(i)) return false;
	}
	return true;
}

/* Polynomial p1: 3x^2 + 2x^1 + 1
Polynomial p2: -1x^2 + 4

Evaluation:
p1(2) = 17
p2(2) = 0

=== Polynomial + Polynomial ===
p1 + p2 = 2x^2 + 2x^1 + 5

=== Polynomial - Polynomial ===
p1 - p2 = 4x^2 + 2x^1 - 3

=== Polynomial * Polynomial ===
p1 * p2 = -3x^4 - 2x^3 + 11x^2 + 8x^1 + 4

=== Polynomial + double ===
p1 + 5 = 3x^2 + 2x^1 + 6

=== Polynomial - double ===
p1 - 3 = 3x^2 + 2x^1 - 2

=== Polynomial * double ===
p1 * 2 = 6x^2 + 4x^1 + 2

=== double + Polynomial ===
10 + p1 = 3x^2 + 2x^1 + 11

=== double - Polynomial ===
7 - p1 = -3x^2 - 2x^1 + 6

=== double * Polynomial ===
3 * p1 = 9x^2 + 6x^1 + 3

Process finished with exit code 0
*/