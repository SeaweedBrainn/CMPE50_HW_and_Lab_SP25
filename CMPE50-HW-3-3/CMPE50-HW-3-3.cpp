//============================================================================
// Name : CMPE50-HW-3-3.cpp
// Author : Hemang Mehra
// Description : The output of HW 3 exercise 3
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream f1("../Input_hw3_3.txt");
    ofstream f2("../Output_hw3_3.txt");

    string array;
    double grade;
    int num = 1;
    f2.setf(ios::fixed);
    f2.precision(2);

    while(f1 >> array) {

        f2.setf(ios:: left);
        f2 << num << ". " << setw(10) << array;

        f2.unsetf(ios:: left);
        for (int i = 0; i < 5; i++) {
            f1 >> grade;
            f2 << setw(7) << grade;
        }
        f2 << endl;
        num++;
    }
}

/* Input file content:

Smith 85.5 90.0 78.25 88.75 92.5
Johnson 80.0 85.5 79.25 87.0 91.0
Williams 75.75 82.5 88.0 79.5 95.25
Brown 92.0 90.25 85.5 88.0 91.75
Davis 89.5 84.25 90.0 85.0 88.5

* Output file content

1. Smith       85.50  90.00  78.25  88.75  92.50
2. Johnson     80.00  85.50  79.25  87.00  91.00
3. Williams    75.75  82.50  88.00  79.50  95.25
4. Brown       92.00  90.25  85.50  88.00  91.75
5. Davis       89.50  84.25  90.00  85.00  88.50
*/


