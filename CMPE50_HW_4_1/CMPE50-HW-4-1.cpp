//============================================================================
// Name : CMPE50-HW-4-1.cpp
// Author : Hemang Mehra
// Description : The output of HW 4 exercise 1
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    string s;
    ifstream f("../InputFile_HW4_1.txt");
    int num = 0;

    if (!f.is_open()) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    while (!f.eof()) {
        getline(f, s);
        num++;
        cout << setw(3) << num << ": " << s << endl;
    }
    f.close();
}

/* Input File: InputFile_HW4_1.txt
 * Output:

  1: With three or four   loggerheads amongst three or four
  2:   score hogsheads. I have    sounded the very
  3: base- string of humility.    Sirrah, I am sworn brother
  4: to a leash of    drawers; and can call them all by
  5:     their christen    names, as Tom, Dick, and Francis.
  6:    They take it already upon    their salvation, that
  7: though   I be but the prince of Wales,      yet I am king
  8: of     courtesy; and tell me flatly I am no proud Jack,
  9:         like Falstaff,          but a Corinthian, a lad of mettle, a
 10:     good        boy,    by the Lord, so they call me, and when I
 11: am king     of England, I shall command all the good
 12:                 lads    in Eastcheap.

Process finished with exit code 0
*/