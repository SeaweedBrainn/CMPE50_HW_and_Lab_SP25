//============================================================================
// Name        : CMPE50_Lab4_Ex2.cpp
// Author      : Hemang Mehra
// Description : The output of lab exercise 4.2
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void executeFunction(istream& f1, ofstream& f2);
void printTable(int array[], int len, ofstream& f2);

int main()
{
    ifstream f1;
    ofstream f2("../LabOutput4-2.txt");
    int key;
    string filename;

    cout << "Enter 1 to input from keyboard. Enter any other number to input from a file: ";
    cin >> key;

    if (key == 1) {
        cout << "Enter the values: ";
        executeFunction(cin, f2);
    }

    else {
        cout << "Enter file name: ";
        cin >> filename;
        f1.open("../"+filename);
        executeFunction(f1, f2);
    }
}

void executeFunction(istream& f1, ofstream& f2) {
    int i;
    int value;
    int array[50];

    for (i=0; i < 50 && f1 >> value && (value >= 1 && value <= 10); i++) array[i] = value;

    printTable(array, i, f2);
    f2.close();
}

void printTable(int array[], int len, ofstream& f2) {
    int frequency[10][2] = {{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0}};

    for (int i=0; i < len ; i++) {
        for (int j=0; j < 10 ; j++) {
            if (array[i] == frequency[j][0]) {
                frequency[j][1]++;
                break;
            }
        }
    }

    f2 << "N   Count" << endl;
    cout << "N   Count" << endl;

    for (int i = 9; i >= 0; i--) {
        if (frequency[i][1] > 0) {
            f2.setf(ios::left); cout.setf(ios::left);
            f2 << setw(6) << frequency[i][0];
            cout << setw(6) << frequency[i][0];

            f2.unsetf(ios::left); cout.unsetf(ios::left);
            f2 << frequency[i][1];
            cout << frequency[i][1];
            f2 << endl; cout << endl;
        }
    }
}

/* Test 1: with keyboard input: 1 2 3 3 2 1 7 8 9 9 10 -1
 * Output:
N   Count
10    1
9     2
8     1
7     1
3     2
2     2
1     2

 * Test 2: with file input: 3 4 1 1 3 4 7 9
 * Output:
N   Count
9     1
7     1
4     2
3     2
1     2
 */