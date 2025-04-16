//============================================================================
//// Name : CMPE50-HW-4-2.cpp
//// Author : Hemang Mehra
//// Description : The output of HW 4 exercise 2
////============================================================================

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void replacePunctuation(char string[]);

int main() {
    char str[100];
    int words = 0;
    int letters = 0;

    cout << "Enter a line: ";
    cin.getline(str, 100);

    replacePunctuation(str);

    for (int i = 0; i <= strlen(str); i++) {
        if (isalpha(str[i])) letters++;

        if ((isspace(str[i]) || str[i] == '\0') && i != 0) {
            if (isalpha(str[i-1])) words++;
        }
    }

    cout << "The input line has " << letters << " letters and " << words << " words." << endl;
}

void replacePunctuation(char string[]) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == '.' || string[i] == ',') string[i] = ' ';
    }
}

/* Input 1: Now is the Winter of our discontent.
 * Output 1: The input line has 29 letters and 7 words.
 *
 * Input 2: Now, is, the, Winter, of, our, discontent.
 * Output 2: The input line has 29 letters and 7 words.
 *
 * Input 3: Now,, is, the, , ,  Winter.. of ,, our..,  discontent.
 * Output 3: The input line has 29 letters and 7 words.
 */