//============================================================================
// Name : CMPE50_Lab8_Ex2.cpp
// Author : Hemang Mehra
// Description : The output of Lab 8 exercise 2
//============================================================================

#include <cstring>
#include <iostream>
using namespace std;

char* delete_repeats(char string[], int size);
int main()
{
    char str[100] = "to be or not to be";
    int size = strlen(str);
    char *noRepeat;
    noRepeat = delete_repeats(str, size);
    cout << noRepeat;
    delete [] noRepeat;
}

char* delete_repeats(char string[], int size) {
    char *result = new char[2];
    bool isRepeated;
    result[0] = string[0];
    result[1] = '\0';
    for (int i = 0; i < size; i++) {
        isRepeated = false;
        for (int j = 0; j < strlen(result); j++) {
            if (tolower(string[i]) == tolower(result[j])) {
                isRepeated = true;
                break;
            }
        }
        if (!isRepeated) {
            char *tempResult = new char[strlen(result) + 1];
            strcpy(tempResult, result);
            tempResult[strlen(tempResult)] = string[i];
            tempResult[strlen(tempResult) + 1] = '\0';
            delete [] result;
            result = new char[strlen(tempResult)];
            strcpy(result, tempResult);
            delete [] tempResult;
        }
    }
    return result;
}

/* OUTPUT with input: "to be or not to be":
 * to bern
 * OUTPUT with input: "that is the question":
 * tha isequon
 */