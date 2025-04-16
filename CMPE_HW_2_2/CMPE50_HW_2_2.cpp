//============================================================================
// Name : CMPE50-HW-2-2.cpp
// Author : Hemang Mehra
// Description : The output of HW 2 exercise 2
//============================================================================

#include <iostream>
#include <cctype>
using namespace std;

void swapFrontBack(int arr[], int size);
void new_line();

int main() {
    char repeat = 'y';

    while (tolower(repeat) == 'y') {
        int size;
        cout << "Enter the size of array: ";
        cin >> size;

        int arr[size];
        cout << "Enter the elements of array: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        new_line();

        swapFrontBack(arr, size);
        cout << "The elements of array after swapping are: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl << endl << "Do you want to go again? (y/n): ";
        cin >> repeat;
        new_line();
        cout << endl;
    }
}

void swapFrontBack(int arr[], int size) {
    if (size == 0) {
        cout << "Error: Array Empty" << endl;
        return;
    }

    int temp;
    temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
}

void new_line() {
    while (cin.get() != '\n') {}
}

/*OUTPUT:
Enter the size of array: 5
Enter the elements of array: 1 2 3 4 5
The elements of array after swapping are: 5 2 3 4 1

Do you want to go again? (y/n): yes

Enter the size of array: 0
Enter the elements of array: Error: Array Empty
The elements of array after swapping are:

Do you want to go again? (y/n): Y

Enter the size of array: 7
Enter the elements of array: 0 1 1 2 3 5 8
The elements of array after swapping are: 8 1 1 2 3 5 0

Do you want to go again? (y/n): Yeess

Enter the size of array: 1
Enter the elements of array: 3
The elements of array after swapping are: 3

Do you want to go again? (y/n): yep

Enter the size of array: 2
Enter the elements of array: 10 01
The elements of array after swapping are: 1 10

Do you want to go again? (y/n): n


Process finished with exit code 0
/*