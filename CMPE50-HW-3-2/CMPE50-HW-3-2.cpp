//============================================================================
// Name : CMPE50-HW-3-2.cpp
// Author : Hemang Mehra
// Description : The output of HW 3 exercise 2
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;

void merge(ifstream & f1, ifstream & f2, ofstream & f3);
int main()
{
    ifstream f1, f2;
    f1.open("../infile1_hw3_2.txt");
    f2.open("../infile2_hw3_2.txt");

    ofstream f3;
    f3.open("../outfile_hw3_2.txt");

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

/* Input file 1: 1 4 9 12 17 23 28 35 40 48 52
 * Input file 2: 2 5 7 14 19 25 30 33 38 45 50 55 60
 * Output file : 1 2 4 5 7 9 12 14 17 19 23 25 28 30 33 35 38 40 45 48 50 52 55 60
 */