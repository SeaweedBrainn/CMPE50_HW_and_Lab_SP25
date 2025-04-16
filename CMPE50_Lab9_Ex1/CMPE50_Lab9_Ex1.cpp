//============================================================================
// Name : CMPE50_Lab9_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of Lab 9 exercise 1
//============================================================================

#include <iostream>
#include "polynomial.h"
using namespace std;

int main() {
    // Create two polynomials:
    // p1(x) = 1 + 2x + 3x^2
    Polynomial p1(2);
    p1.set_coeff(0, 1);
    p1.set_coeff(1, 2);
    p1.set_coeff(2, 3);

    // p2(x) = 4 + 0x + -1x^2
    Polynomial p2(2);
    p2.set_coeff(0, 4);
    p2.set_coeff(2, -1);

    // Display both polynomials
    cout << "Polynomial p1: " << p1 << endl;
    cout << "Polynomial p2: " << p2 << endl;

    // Test evaluate
    double x = 2.0;
    cout << "\nEvaluation:" << endl;
    cout << "p1(" << x << ") = " << p1.evaluate(x) << endl;
    cout << "p2(" << x << ") = " << p2.evaluate(x) << endl;

    // Test Polynomial + Polynomial
    cout << "\n=== Polynomial + Polynomial ===" << endl;
    Polynomial sum = p1 + p2;
    cout << "p1 + p2 = " << sum << endl;

    // Test Polynomial - Polynomial
    cout << "\n=== Polynomial - Polynomial ===" << endl;
    Polynomial diff = p1 - p2;
    cout << "p1 - p2 = " << diff << endl;

    // Test Polynomial * Polynomial
    cout << "\n=== Polynomial * Polynomial ===" << endl;
    Polynomial prod = p1 * p2;
    cout << "p1 * p2 = " << prod << endl;

    // Test Polynomial + int
    cout << "\n=== Polynomial + double ===" << endl;
    cout << "p1 + 5 = " << (p1 + 5) << endl;

    // Test Polynomial - int
    cout << "\n=== Polynomial - double ===" << endl;
    cout << "p1 - 3 = " << (p1 - 3) << endl;

    // Test Polynomial * int
    cout << "\n=== Polynomial * double ===" << endl;
    cout << "p1 * 2 = " << (p1 * 2) << endl;

    // Test int + Polynomial
    cout << "\n=== double + Polynomial ===" << endl;
    cout << "10 + p1 = " << (10 + p1) << endl;

    // Test int - Polynomial
    cout << "\n=== double - Polynomial ===" << endl;
    cout << "7 - p1 = " << (7 - p1) << endl;

    // Test int * Polynomial
    cout << "\n=== double * Polynomial ===" << endl;
    cout << "3 * p1 = " << (3 * p1) << endl;

    return 0;
}

