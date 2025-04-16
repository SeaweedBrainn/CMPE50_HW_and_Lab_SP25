//============================================================================
// Name        : CMPE50_Lab4_Ex1.cpp
// Author      : Hemang Mehra
// Description : The output of lab exercise 4.1
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    ifstream f1("../LabInput4-1.txt");
    ofstream f2("../LabOutput4-1.txt");

    if (!f1.is_open()) {
        f2 << "Error opening file" << endl;
        return 1;
    }

    string array;
    char value;

    while (f1 >> value) {
        if (value != '\n' && value != ' ' && value != '.' && value != '?' && value != '!' && value != ',')
            array += toupper(value);
    }

    f2 << array;
    f1.close();
    f2.close();
}

/* Input File: LabInput4-1.txt
 * Output File: LabOutput4-1.txt
 * Output File Contents: HELLOTHISISASAMPLETESTDATAFILE
 */
