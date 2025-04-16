//============================================================================
// Name : CMPE50-HW-4-3.cpp
// Author : Hemang Mehra
// Description : The output of HW 4 exercise 3
//============================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string piglatin(string s);

int main()
{
    string first, last, pg;

    cout << "Enter your first name: ";
    cin >> first;

    cout << "Enter your last name: ";
    cin >> last;

    pg = piglatin(first) + ' ' + piglatin(last);
    cout << "Your name in pig latin is " << pg << endl;
}

string piglatin(string s) {
    string pig;
    string vowels = "aeiou";
    bool isVowel = false;

    for (char vowel : vowels) {
        if (vowel == tolower(s[0])) {
            isVowel = true;
            break;
        }
    }

    if (isVowel) {
        pig += toupper(s[0]);

        for (int i = 1; i < s.size(); i++) {
            pig += tolower(s[i]);
        }
        pig += "way";
    }

    else {
        pig += toupper(s[1]);

        for (int i = 2; i < s.size(); i++) {
            pig += tolower(s[i]);
        }
        pig += tolower(s[0]);
        pig += "ay";
    }

    return pig;
}

/* OUTPUT:
 *
 * Enter your first name: Erin
 * Enter your last name: Jones
 * Your name in pig latin is Erinway Onesjay
 */