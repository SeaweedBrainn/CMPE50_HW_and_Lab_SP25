//============================================================================
// Name : CMPE50_HW7_Ex2.cpp
// Author : Hemang Mehra
// Description : The output of HW7 exercise 2.
//============================================================================

#include <iostream>
using namespace std;

void reverse_array(int* arr, const int size) {
    int* front = arr;
    int* back = arr + size - 1;
    int temp;
    while (front != back && front != back + 1) {
        temp = *front;
        *front = *back;
        *back = temp;
        front++;
        back--;
    }
}

void take_input(int* &arr, int& size) {
    cout << "Enter the size of the array: ";
    cin >> size;
    arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

int main()
{
    int size, *arr;
    take_input(arr, size);
    reverse_array(arr, size);
    cout << "Reversed array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    delete [] arr;
}

/* OUTPUTS:
Enter the size of the array: 10
Enter the elements of the array: 1 2 3 4 5 6 7 8 9 10
Reversed array: 10 9 8 7 6 5 4 3 2 1

Enter the size of the array: 9
Enter the elements of the array: 1 2 3 4 5 6 7 8 9
Reversed array: 9 8 7 6 5 4 3 2 1
*/