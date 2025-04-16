//============================================================================
// Name : CMPE50_Lab5_Ex2.cpp
// Author : Hemang Mehra
// Description : The output of Lab 5 exercise 2
//============================================================================

#include <iostream>
#include <string>
using namespace std;

bool is_alpha(char c);
void new_line();

int main() {
    string iline, line, oline;
    char repeat = 'y';

    while (tolower(repeat) == 'y')
    {
        oline = "";
        iline = "";
        cout << "Enter a line of text: ";
        getline(cin, line);


        for (int i = 0; i < line.length(); i++) {
            if (is_alpha(line[i])){
                iline += tolower(line[i]);
            }
            else {
                iline += " ";
            }
        }

        for (int i = 0; i < line.length(); i = i) {
            if (iline.substr(i, 4) == " he "){
                oline += " she or him ";
                i = i + 3;
            }
            else if (iline.substr(i, 5) == " she ") {
                oline += " she or him";
                i = i + 4;
            }
            else if (iline.substr(i, 5) == " him " || iline.substr(i, 5) == " her ") {
                oline += " her or him";
                i = i + 4;
            }
            else if (iline.substr(i, 5) == " his ") {
                oline += " her(s) or his";
                i = i + 4;
            }
            else if (iline.substr(i, 8) == " her(s) ") {
                oline += " her(s) or his";
                i = i + 7;
            }
            else {
                oline += line[i];
                i++;
            }
        }
        oline[0] = toupper(oline[0]);
        cout << "The output is: " << oline << endl << endl;

        cout << "Do you want to go again? (y/n): ";
        cin >> repeat;
        new_line();
    }
}

bool is_alpha(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

void new_line()
{
    while (cin.get() != '\n') {}
}

/* OUTPUT:

Enter a line of text: If a student needs help, he should ask his teacher to guide him.
The output is: If a student needs help, she or him  should ask her(s) or his teacher to guide her or him.

Do you want to go again? (y/n): y
Enter a line of text: See an adviser, talk to him, and listen to him.
The output is: See an adviser, talk to her or him, and listen to her or him.

Do you want to go again? (y/n): n

Process finished with exit code 0
*/