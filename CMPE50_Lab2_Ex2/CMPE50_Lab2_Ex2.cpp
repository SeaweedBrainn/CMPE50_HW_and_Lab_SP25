//============================================================================
// Name        : CMPE50_Lab2_Ex2.cpp
// Author      : Hemang Mehra
// Description : The output of lab exercise 2.2
//============================================================================

#include <iostream>
using namespace std;

bool hasPunctuation(char sentence[]);
void readValues(char arr[], int N);
void displayValues(char arr[], int N);

int main() {
    int N;
    cout << "You will enter a string, and the string will be returned back to you reversed." << endl;
    cout << "If the string ends with a punctuation (like '.', '!', '?', '/' and so on) then they the punctuation will be omitted" << endl;
    cout << "\nEnter the number of characters in string: ";
    cin >> N;
    char* arr = new char[N+1];


    readValues(arr, N);
    if (hasPunctuation(arr)) {
        N = N-1;
    }
    cout << endl;
    displayValues(arr, N);

    return 0;
}

bool hasPunctuation(char sentence[]) {
    char lastLetter = sentence[strlen(sentence)-1];
    if ((lastLetter >= 33 && lastLetter <= 47) || (lastLetter >= 58 && lastLetter <= 64)) {
        return true;
    }
    return false;
}

void readValues(char arr[], int N) {
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    arr[N] = '\0';
}

void displayValues(char arr[], int N) {
    cout << "The reverse string for " << arr << " is:" << endl;
    for (int i = N-1; i >= 0; i--) {
        cout << arr[i];
    }
}

/* OUTPUT:
You will enter a string, and the string will be returned back to you reversed.
If the string ends with a punctuation (like '.', '!', '?', '/' and so on) then they the punctuation will be omitted

Enter the number of characters in string: 10
abcdefghi!

The reverse string for abcdefghi! is:
ihgfedcba
Process finished with exit code 0
*/

/* ALGORITHM
 * 1. Declare a pointer arr* with the allocated memory of input bytes (N) + 1
 * 2. Read the values from the user input using a loop from i = 0 to i = N and append a null character at the end.
 * 3. Check if the char array contains a punctuation by comparing the last element with the ascii values of punctuation marks.
      If yes then put N = N - 1. Else skip directly to step 4.
 * 4. Iterate the array from index i = N - 1 to i = 0 and print the elements as you iterate them
      If there was a punctuation then it got skipped due to step 3 decreasing the value of N by 1.
 */
