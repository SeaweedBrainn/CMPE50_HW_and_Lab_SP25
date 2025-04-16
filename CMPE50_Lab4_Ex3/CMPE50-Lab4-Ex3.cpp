//============================================================================
// Name : CMPE50-Lab4-Ex3.cpp
// Author : Hemang Mehra
// Description : The output of Lab 4 exercise 3
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

void merge(ifstream & f1, ifstream & f2, ofstream & f3);
int main()
{
    ifstream f1, f2;
    f1.open("../LabInput4-3.txt");
    f2.open("../LabInput4-4.txt");

    ofstream f3;
    f3.open("../LabOutput4_ex3.txt");

    merge(f1, f2, f3);
}

void merge(ifstream & f1, ifstream & f2, ofstream & f3) {
    int var1, var2;
    int sorted[100];

    int i = 0;

    while (f1 >> var1) {
        sorted[i] = var1;
        i++;
    }
    while (f2 >> var2) {
        sorted[i] = var2;
        i++;
    }

    sort(sorted, sorted+i);

    for (int j = 0; j < i; j++) {
        f3 << sorted[j] << " ";
    }

    f1.close();
    f2.close();
    f3.close();
}

/* Input file 1: 6 13 15 22 33 76 88 99
 * Input file 2: 31 40 52 60 62 89
 * Output file : 6 13 15 22 31 33 40 52 60 62 76 88 89 99
 */