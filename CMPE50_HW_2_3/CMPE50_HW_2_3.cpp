//============================================================================
// Name : CMPE50-HW-2-3.cpp
// Author : Hemang Mehra
// Description : The output of HW 2 exercise 3
//============================================================================

#include <iostream>
#include <cctype>
using namespace std;

int countEvens(int arr[], int size);
void new_line();

int main() {
    char repeat = 'y';
    int count;

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

        count = countEvens(arr, size);
        cout << "The number of even elements in the array is: " << count;

        cout << endl << endl << "Do you want to go again? (y/n): ";
        cin >> repeat;
        new_line();
        cout << endl;
    }
}

int countEvens(int arr[], int size) {
    if (size == 0) {
        cout << "Error: Array Empty" << endl;
        return 0;
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) count++;
    }
    return count;
}

void new_line() {
    while (cin.get() != '\n') {}
}

/*OUTPUT:
Enter the size of array: 0
Enter the elements of array: Error: Array Empty
The number of even elements in the array is: 0

Do you want to go again? (y/n): yes

Enter the size of array: 5
Enter the elements of array: 1 2 3 4 5
The number of even elements in the array is: 2

Do you want to go again? (y/n): y

Enter the size of array: 10
Enter the elements of array: 0 1 1 2 3 5 8 13 21 34
The number of even elements in the array is: 4

Do you want to go again? (y/n): YES

Enter the size of array: 1
Enter the elements of array: 2
The number of even elements in the array is: 1

Do you want to go again? (y/n): yesss

Enter the size of array: 7
Enter the elements of array: 7 7 7 7 7 7 7
The number of even elements in the array is: 0

Do you want to go again? (y/n): n


Process finished with exit code 0
*/