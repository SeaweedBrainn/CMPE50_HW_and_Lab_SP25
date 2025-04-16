//============================================================================
// Name : CMPE50_Lab5_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of Lab 5 exercise 1
//============================================================================

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    char line[101];
    char word[101];

    cout << "Please enter a line of text:" << endl;
    cin.getline(line, 100, '.');
    cout << endl;
    cout << "Output: " << endl;

    int i, j = 0;

    for (i = 0; line[i] != '\0'; i = i + j + 1) {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
            j = 0;
            continue;
        }
        for (j = 0; (line[j+i] != ' '); j++) {
            if (line[j+i] == '\n' || line[j+i] == '\0' || line[j+i] == '\t') break;
        }
        strncpy(word, &line[i], j);
        word[j] = '\0';

        word[0] = toupper(word[0]);
        for (int k = 1; k < strlen(word); k++) {
            word[k] = tolower(word[k]);
        }

        cout << word;
        if (line[i+j+1] != '\0') cout << " ";
    }
    cout << '.' << endl;

    return 0;
}

/* OUTPUT:

Please enter a line of text:
        noW    iS thE   	TiMe    fOr    aLl
   gOOD 		MEN   TO     ComE TO    tHe
    aId
  oF
    ThE     CounTRY.

Output:
Now Is The Time For All Good Men To Come To The Aid Of The Country.

Process finished with exit code 0
*/