//
// Created by Hemang Mehra on 4/15/25.
//

#include <stdio.h>
#include "Complex.h"

Complex::Complex() {
    real = imaginary = 0;
}

Complex::Complex(double re) {
    real = re;
    imaginary = 0;
}

Complex::Complex(double re, double im) {
    real = re;
    imaginary = im;
}

Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.real + b.real, a.imaginary + b.imaginary);
}

Complex operator-(const Complex &a, const Complex &b) {
    return Complex(a.real - b.real, a.imaginary - b.imaginary);
}

Complex operator*(const Complex &a, const Complex &b) {
    return Complex(a.real * b.real - a.imaginary * b.imaginary,a.real * b.imaginary + a.imaginary * b.real);
}

ostream &operator<<(ostream &os, const Complex &a) {
    if (a.imaginary >= 0) os << a.real << " + " << a.imaginary << "i";
    else os << a.real << " - " << fabs(a.imaginary) << "i";
    return os;
}

Complex operator+(const Complex &c1, double re) {
    return c1 + Complex(re);
}

Complex operator+(double re, const Complex &c1) {
    return c1 + Complex(re);
}

Complex operator-(const Complex &c1, double re) {
    return c1 - Complex(re);
}

Complex operator-(double re, const Complex &c1) {
    return Complex(re) - c1;
}

Complex operator*(const Complex &c1, double re) {
    return c1 * Complex(re);
}

Complex operator*(double re, const Complex &c1) {
    return c1 * Complex(re);
}

/* === Constructors ===
c1: 0 + 0i
c2: 3 + 4i
c3: 5 + 0i

=== Complex + Complex ===
c2 + c3 = 8 + 4i

=== Complex - Complex ===
c2 - c3 = -2 + 4i

=== Complex * Complex ===
c2 * c3 = 15 + 20i

=== Complex + double ===
c2 + 2.5 = 5.5 + 4i

=== Complex - double ===
c2 - 1.5 = 1.5 + 4i

=== Complex * double ===
c2 * 3.0 = 9 + 12i

=== double + Complex ===
7.0 + c2 = 10 + 4i

=== double - Complex ===
10.0 - c2 = 7 - 4i

=== double * Complex ===
2.0 * c2 = 6 + 8i

Process finished with exit code 0
*/
