//============================================================================
// Name : CMPE50-HW-1-3.cpp
// Author : Hemang Mehra
// Description : The output of HW 1 exercise 3
//============================================================================

#include <iostream>
using namespace std;

double maximum(double a, double b);
double maximum(double a, double b, double c);

int main() {
    cout << "Maximum out of 1.0 and 2.0 is: " <<maximum(1.0, 2.0) << endl;
    cout << "Maximum out of 1.0, 2.0, and 3.0 is: " << maximum(1.0, 2.0, 3.0) << endl;
}

double maximum(double a, double b) {
    return a > b ? a : b;
}

double maximum(double a, double b, double c) {
    return c > (a > b ? a : b) ? c : (a > b ? a : b);
}

/* OUTPUT
 * Maximum out of 1.0 and 2.0 is: 2
 * Maximum out of 1.0, 2.0, and 3.0 is: 3
 *
 * Process finished with exit code 0
 */
