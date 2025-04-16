//============================================================================
// Name        : CMPE50_Lab3_Ex2.cpp
// Author      : Hemang Mehra
// Description : The output of lab exercise 3.2
//============================================================================

#include <iostream>
using namespace std;

void setMatrix(int EmptyMatrix[][3]);
int typeOfMatrix(int Matrix[][3]);
void displayMatrix(int Matrix[][3]);
bool isNull(int Matrix[][3]);

int main() {
    int Matrix[3][3];
    setMatrix(Matrix);
    cout << endl;
    displayMatrix(Matrix);
    int type = typeOfMatrix(Matrix);
    if (type == 1) cout << "This is a null matrix." << endl;
    else if (type == 2) cout << "This is a upper triangular matrix." << endl;
    else if (type == 3) cout << "This is a lower triangular matrix." << endl;
    else if (type == 4) cout << "This is a diagonal matrix." << endl;
    else cout << "This is a normal matrix." << endl;
}

void setMatrix(int EmptyMatrix[][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << "Enter element of row " << row+1 << " and column " << col+1 << ": ";
            cin >> EmptyMatrix[row][col];
        }
    }
}

void displayMatrix(int Matrix[][3]) {
    cout << "Your matrix:" << endl;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << Matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int typeOfMatrix(int Matrix[][3]) {
    if (Matrix[0][1] == 0 && Matrix[0][2] == 0 && Matrix[1][2] == 0) {
        if (isNull(Matrix)) return 1;
        if (Matrix[1][0] == 0 && Matrix[2][0] == 0 && Matrix[2][2] == 0) return 4;
        return 3;
    }
    if (Matrix[1][0] == 0 && Matrix[2][0] == 0 && Matrix[2][2] == 0) {
        if (isNull(Matrix)) return 1;
        return 2;
    }
    return 5;
}

bool isNull(int Matrix[][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (Matrix[row][col] != 0) return false;
        }
    }
    return true;
}

/*OUTPUT:

Enter element of row 1 and column 1: 1
Enter element of row 1 and column 2: 1
Enter element of row 1 and column 3: 3
Enter element of row 2 and column 1: 0
Enter element of row 2 and column 2: 2
Enter element of row 2 and column 3: 4
Enter element of row 3 and column 1: 0
Enter element of row 3 and column 2: 0
Enter element of row 3 and column 3: 0

Your matrix:
1 1 3
0 2 4
0 0 0

This is a upper triangular matrix.

Process finished with exit code 0
*/