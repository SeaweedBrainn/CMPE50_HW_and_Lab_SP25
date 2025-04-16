//============================================================================
// Name : CMPE50_Lab9_Ex2.cpp
// Author : Hemang Mehra
// Description : The output of Lab 9 exercise 2
//============================================================================

#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
    // === Constructor tests ===
    Complex c1;                   // Default constructor (0 + 0i)
    Complex c2(3, 4);             // 3 + 4i
    Complex c3(5);                // 5 + 0i

    cout << "=== Constructors ===" << endl;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;

    // === Complex + Complex ===
    Complex sum = c2 + c3;
    cout << "\n=== Complex + Complex ===" << endl;
    cout << "c2 + c3 = " << sum << endl;

    // === Complex - Complex ===
    Complex diff = c2 - c3;
    cout << "\n=== Complex - Complex ===" << endl;
    cout << "c2 - c3 = " << diff << endl;

    // === Complex * Complex ===
    Complex prod = c2 * c3;
    cout << "\n=== Complex * Complex ===" << endl;
    cout << "c2 * c3 = " << prod << endl;

    // === Complex + double ===
    Complex sum2 = c2 + 2.5;
    cout << "\n=== Complex + double ===" << endl;
    cout << "c2 + 2.5 = " << sum2 << endl;

    // === Complex - double ===
    Complex diff2 = c2 - 1.5;
    cout << "\n=== Complex - double ===" << endl;
    cout << "c2 - 1.5 = " << diff2 << endl;

    // === Complex * double ===
    Complex prod2 = c2 * 3.0;
    cout << "\n=== Complex * double ===" << endl;
    cout << "c2 * 3.0 = " << prod2 << endl;

    // === double + Complex ===
    Complex sum3 = 7.0 + c2;
    cout << "\n=== double + Complex ===" << endl;
    cout << "7.0 + c2 = " << sum3 << endl;

    // === double - Complex ===
    Complex diff3 = 10.0 - c2;
    cout << "\n=== double - Complex ===" << endl;
    cout << "10.0 - c2 = " << diff3 << endl;

    // === double * Complex ===
    Complex prod3 = 2.0 * c2;
    cout << "\n=== double * Complex ===" << endl;
    cout << "2.0 * c2 = " << prod3 << endl;

    return 0;
}

/*
=== Constructors ===
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
