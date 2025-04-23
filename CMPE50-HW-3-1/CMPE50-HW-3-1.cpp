//============================================================================
// Name : CMPE50-HW-3-1.cpp
// Author : Hemang Mehra
// Description : The output of HW 3 exercise 1
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("../Inputfile_hw3_1.txt");
    double sum = 0;
    double value;
    double numValues = 0;


    while (f >> value) {
        numValues++;
        sum += value;
    }

    f.close();

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    if (numValues == 0)
        cout << "The mean of all values in file is 0.0" << endl;
    else
        cout << "The mean of all values in file is " << sum / numValues << endl;
    return 0;
}

/* Values in input file: 23.45 67.89  12.34 98.76 54.32 76.54 45.67 89.01 34.56 65.43
 *
 * OUTPUT: The mean of all values in file is 56.797000
 */