//============================================================================
// Name : CMPE50_Lab8_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of Lab 8 exercise 1
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

class airplane {
    public:
    airplane(istream &f);
    ~airplane();
    void assignSeat(string seat);
    bool isFull();

    private:
    int numRows, numCols, seatsEmpty;
    char **seats;
    void display();
};

int main() {
    int choice;

    cout << "Enter 1 to enter seats from the console." << endl;
    cout << "Enter any other integer to enter seats from a file: ";
    cin >> choice;

    if (choice == 1) {
        airplane plane(cin);
        string seat;
        while (!plane.isFull()) {
            cout << "Enter seat name: ";
            cin >> seat;
            if (seat == "exit") break;
            plane.assignSeat(seat);
        }
    }

    else {
        string filename;
        string seat;

        cout << "File name: ";
        cin >> filename;

        ifstream fin(("../"+filename).c_str());

        airplane plane(fin);
        fin >> seat;
        while (!plane.isFull() && !fin.eof()) {
            plane.assignSeat(seat);
            fin >> seat;
        }
    }
}

airplane::airplane(istream &f) {
    numCols = 6;

    cout << "Please enter the number of rows you want to see: ";
    f >> numRows;
    seatsEmpty = numRows * numCols;

    seats = new char*[numRows];

    for (int i = 0; i < numRows; i++) {
        seats[i] = new char[numCols];
    }

    for (int i = 0; i < numRows*numCols; i++) {
        int row = i / numCols;
        int col = i % numCols;

        seats[row][col] = static_cast<char>(col+'A');
    }

    cout << "\nThe seats have been generated: " << endl;
    display();
}

airplane::~airplane() {
    delete[] seats;
    seats = nullptr;
}

void airplane::display() {
    for (int i = 0; i < numRows*numCols; i++) {
        int row = i / numCols;
        int col = i % numCols;
        if (i % numCols == 0) cout << row+1 << " ";
        cout << seats[row][col] << " ";
        if ((i+1) % numCols == 0) cout << endl;
    }
    cout << endl;
}


void airplane::assignSeat(string seat) {
    for (int i = 0; i < numRows*numCols; i++) {
        int row = i / numCols;
        int col = i % numCols;
        if (seat == to_string(row+1) + seats[row][col] ||
            seat == to_string(row+1) + static_cast<char>(tolower(seats[row][col]))
            && seats[row][col] != 'X') {
            seats[row][col] = 'X';
            seatsEmpty--;
            cout << "You have been assigned the seat " << seat << endl;;
            display();
            return;
        }
    }
    cout << "The seat " << seat << " is not available." << endl;
    display();
}

bool airplane::isFull() {
    return (seatsEmpty == 0);
}

/* Output from console:
Enter 1 to enter seats from the console.
Enter any other integer to enter seats from a file: 1
Please enter the number of rows you want to see: 3

The seats have been generated:
1 A B C D
2 A B C D
3 A B C D

Enter seat name: 3a
You have been assigned the seat 3a
1 A B C D
2 A B C D
3 X B C D

Enter seat name: 3A
The seat 3A is not available.
1 A B C D
2 A B C D
3 X B C D

Enter seat name: 1b
You have been assigned the seat 1b
1 A X C D
2 A B C D
3 X B C D

Enter seat name: 4f
The seat 4f is not available.
1 A X C D
2 A B C D
3 X B C D

Enter seat name: 2d
You have been assigned the seat 2d
1 A X C D
2 A B C X
3 X B C D

Enter seat name: 2c
You have been assigned the seat 2c
1 A X C D
2 A B X X
3 X B C D

Enter seat name: 2d
The seat 2d is not available.
1 A X C D
2 A B X X
3 X B C D

Enter seat name: exit
*/

/* Output from input file:
Input File Contents: 5 1A 2A 3A 4b 1b 2C 2D 3c 3a 3f 3b 2b 1c 1d 3d
Output:

Enter 1 to enter seats from the console.
Enter any other integer to enter seats from a file: 2
File name: InputFile.txt
Please enter the number of rows you want to see:
The seats have been generated:
1 A B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D

You have been assigned the seat 1A
1 X B C D
2 A B C D
3 A B C D
4 A B C D
5 A B C D

You have been assigned the seat 2A
1 X B C D
2 X B C D
3 A B C D
4 A B C D
5 A B C D

You have been assigned the seat 3A
1 X B C D
2 X B C D
3 X B C D
4 A B C D
5 A B C D

You have been assigned the seat 4b
1 X B C D
2 X B C D
3 X B C D
4 A X C D
5 A B C D

You have been assigned the seat 1b
1 X X C D
2 X B C D
3 X B C D
4 A X C D
5 A B C D

You have been assigned the seat 2C
1 X X C D
2 X B X D
3 X B C D
4 A X C D
5 A B C D

You have been assigned the seat 2D
1 X X C D
2 X B X X
3 X B C D
4 A X C D
5 A B C D

You have been assigned the seat 3c
1 X X C D
2 X B X X
3 X B X D
4 A X C D
5 A B C D

The seat 3a is not available.
1 X X C D
2 X B X X
3 X B X D
4 A X C D
5 A B C D

The seat 3f is not available.
1 X X C D
2 X B X X
3 X B X D
4 A X C D
5 A B C D

You have been assigned the seat 3b
1 X X C D
2 X B X X
3 X X X D
4 A X C D
5 A B C D

You have been assigned the seat 2b
1 X X C D
2 X X X X
3 X X X D
4 A X C D
5 A B C D

You have been assigned the seat 1c
1 X X X D
2 X X X X
3 X X X D
4 A X C D
5 A B C D

You have been assigned the seat 1d
1 X X X X
2 X X X X
3 X X X D
4 A X C D
5 A B C D

You have been assigned the seat 3d
1 X X X X
2 X X X X
3 X X X X
4 A X C D
5 A B C D


Process finished with exit code 0

*/

