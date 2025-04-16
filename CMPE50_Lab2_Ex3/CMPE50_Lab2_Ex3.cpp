//============================================================================
// Name        : CMPE50_Lab2_Ex3.cpp
// Author      : Hemang Mehra
// Description : The output of lab exercise 2.3
//============================================================================

#include <iostream>
using namespace std;

int main() {
    int arr[10];
    cout << "Enter 10 numbers to make an array with: ";

    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        else if (arr[i] < min) {
            min = arr[i];
        }
    }

    for (int i = 0; i < 10; i++) {
        if (arr[i] == max) {
            arr[i] = min;
        }
    }

    max = arr[0];
    for (int i = 0; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "The second largest element is: " << max << endl;

    return 0;
}

/* OUTPUT:
Enter 10 numbers to make an array with: 1 2 9 3 4 9 8 5 4 0
The second largest element is: 8

Process finished with exit code 0
 */

/* ALGORITHM:
 * 1. Declare an array and read values into it using a for loop
 * 2. Declare variables max and min which hold the first element of array at start
 * 3. Iterate through the array with i = 0 to 9
      a) If an element is greater than max then replace the max with the element
      b) If an element is smaller than min then replace the min with that element
 * 4. Iterate once more through the array and replace all occurence of max in the array with min.
 * 5. Again let max hold the first element of array
 * 6. Repeat step 3a and you will get the second largest element in the array due to step 4 replacing the largest elements with the smallest element.
 */