//============================================================================
// Name : CMPE50_Lab7.cpp
// Author : Hemang Mehra
// Description : The output of Lab 6 exercise 3
//============================================================================

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Rational {
public:
    Rational();
    Rational(int num, int den);
    void input(istream& f);
    void output(ostream& f);
    friend Rational add(const Rational& num1, const Rational& num2);
    friend Rational sub(const Rational& num1, const Rational& num2);
    friend Rational mul(const Rational& num1, const Rational& num2);
    friend Rational div(const Rational& num1, const Rational& num2);
    friend bool equal(const Rational& num1, const Rational& num2);
    friend bool less_than(const Rational& num1, const Rational& num2);
private:
    int numerator, denominator;
    int getGCD();
    void normalize();
};

int main() {
    Rational r1(3, 4), r2(5, 6);

    cout << "Rational numbers: ";
    r1.output(cout);
    cout << " and ";
    r2.output(cout);
    cout << endl;

    Rational sum = add(r1, r2);
    cout << "Sum: ";
    sum.output(cout);
    cout << endl;

    Rational difference = sub(r1, r2);
    cout << "Difference: ";
    difference.output(cout);
    cout << endl;

    Rational product = mul(r1, r2);
    cout << "Product: ";
    product.output(cout);
    cout << endl;

    Rational quotient = div(r1, r2);
    cout << "Quotient: ";
    quotient.output(cout);
    cout << endl;

    cout << "Are they equal? " << (equal(r1, r2) ? "Yes" : "No") << endl;

    cout << "Is r1 less than r2? " << (less_than(r1, r2) ? "Yes" : "No") << endl;

    Rational r3;
    cout << "Enter a rational number (format: a/b): ";
    r3.input(cin);
    cout << "You entered: ";
    r3.output(cout);
    cout << endl;

    return 0;
}


Rational add(const Rational& num1, const Rational& num2) {
    Rational result;
    result.numerator = num1.numerator * num2.denominator + num2.numerator * num1.denominator;
    result.denominator = num1.denominator * num2.denominator;
    result.normalize();
    return result;
}

Rational sub(const Rational& num1, const Rational& num2) {
    Rational result;
    result.numerator = num1.numerator * num2.denominator - num2.numerator * num1.denominator;
    result.denominator = num1.denominator * num2.denominator;
    result.normalize();
    return result;
}

Rational mul(const Rational& num1, const Rational& num2) {
    Rational result;
    result.numerator = num1.numerator * num2.numerator;
    result.denominator = num1.denominator * num2.denominator;
    result.normalize();
    return result;
}

Rational div(const Rational& num1, const Rational& num2) {
    Rational result;
    result.numerator = num1.numerator * num2.denominator;
    result.denominator = num1.denominator * num2.numerator;
    result.normalize();
    return result;
}

bool equal(const Rational& num1, const Rational& num2) {
    return (num1.numerator*num2.denominator == num2.numerator*num1.denominator);
}

bool less_than(const Rational& num1, const Rational& num2) {
    return (num1.numerator*num2.denominator < num2.numerator*num1.denominator);
}

int Rational::getGCD() {
    int temp;
    int n1 = abs(numerator), n2 = abs(denominator);
    while (n2 != 0)
    {
        temp = n1;
        n1 = n2;
        n2 = temp % n2;
    }
    return abs(n1);
}

void Rational::normalize() {
    if (denominator < 0) {
        denominator *= -1;
        numerator *= -1;
    }
    int gcd = getGCD();
    numerator /= gcd;
    denominator /= gcd;
}

void Rational::input(istream& f) {
    string s;
    getline(f, s, '/');
    numerator = stoi(s);
    f >> denominator;
    normalize();
}

void Rational::output(ostream& f) {
    f << numerator << "/" << denominator;
}

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num, int den) {
    numerator = num;
    denominator = den;
    normalize();
}



/* OUTPUT:
Rational numbers: 3/4 and 5/6
Sum: 19/12
Difference: -1/12
Product: 5/8
Quotient: 9/10
Are they equal? No
Is r1 less than r2? Yes
Enter a rational number (format: a/b): -4/-8
You entered: 1/2

Process finished with exit code 0
*/