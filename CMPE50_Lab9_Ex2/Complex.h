//
// Created by Hemang Mehra on 4/15/25.
//

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex
{
public:
    Complex();
    Complex(double re, double im);
    Complex(double re);

    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
    friend Complex operator*(const Complex &c1, const Complex &c2);

    friend Complex operator+(const Complex &c1, double re);
    friend Complex operator-(const Complex &c1, double re);
    friend Complex operator*(const Complex &c1, double re);

    friend Complex operator+(double re,const Complex &c1);
    friend Complex operator-(double re,const Complex &c1);
    friend Complex operator*(double re,const Complex &c1);

    friend ostream& operator<<(ostream &os, const Complex &c);
private:
    double real, imaginary;
};

#endif //COMPLEX_H
