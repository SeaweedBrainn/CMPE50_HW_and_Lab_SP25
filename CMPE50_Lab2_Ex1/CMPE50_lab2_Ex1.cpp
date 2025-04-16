//============================================================================
// Name        : CMPE50_Lab2_Ex1.cpp
// Author      : Hemang Mehra
// Description : The output of lab exercise 2.1
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

int Add(int a, int b);
char* Add(char a[], char b[]);
double Add(double a, double b);

int main() {
    char repeat = 'y';
    while (repeat == 'y') {
        int choice;
        cout << "Please enter what do you want to add" << endl;
        cout << "1. Two Double Numbers" << endl;
        cout << "2. Two Integer Numbers" << endl;
        cout << "3. Two Strings" << endl;
        cout << "Enter: ";
        cin >> choice;
        if (choice < 1 || choice > 3) {
            cout << "Invalid Input" << endl;
            cout << endl;
            continue;
        }
        cout << endl;
        if (choice == 1) {
            double a, b;
            cout << "Please enter first double number: ";
            cin >> a;
            cout << "Please enter second double number: ";
            cin >> b;
            cout << Add(a, b) << endl;
        }
        else if (choice == 2) {
            int a, b;
            cout << "Please enter first integer number: ";
            cin >> a;
            cout << "Please enter second integer number: ";
            cin >> b;
            cout << Add(a,b) << endl;
        }
        else if (choice == 3) {
            char a[100], b[100];
            cout << "Please first string without any spaces in between: ";
            cin >> a;
            cout << "Please second string without any spaces in between: ";
            cin >> b;
            cout << Add(a, b) << endl;
        }

        cout << endl;
        cout << "Do you want to continue?(y/n):";
        cin >> repeat;
        cout << endl;
    }
    return 0;
}

int Add(int a, int b){
    return a + b;
}

double Add(double a, double b) {
    return a + b;
}

char *Add(char a[], char b[]) {
    int len = strlen(a) + strlen(b) + 2;
    char *result = new char[len];
    strcat(result, a);
    strcat(result, " ");
    return strcat(result, b);
}

/* OUTPUT:
Please enter what do you want to add
1. Two Double Numbers
2. Two Integer Numbers
3. Two Strings
Enter: 1

Please enter first double number: 1.0
Please enter second double number: 2.0
3

Do you want to continue?(y/n):y

Please enter what do you want to add
1. Two Double Numbers
2. Two Integer Numbers
3. Two Strings
Enter: 2

Please enter first integer number: 12
Please enter second integer number: 13
25

Do you want to continue?(y/n):y

Please enter what do you want to add
1. Two Double Numbers
2. Two Integer Numbers
3. Two Strings
Enter: 3

Please first string without any spaces in between: Hello,
Please second string without any spaces in between: World
Hello, World

Do you want to continue?(y/n):n


Process finished with exit code 0 /*

/* ALGORITHM
 * 1. Ask for input on which operation to perform (double, integer, or string adition)
 * 2. If input is invalid ( <0 or >3) skip current iteration and return to step 1, otherwise go to step 3
 * 3. Trigger the correct function according to the input
 * 4. Get input from user for the doubles/ ints/ strings used
 * 5. Return the addition output
 * 6. Ask user if they want to repeat the calculations. Go to step 1 if yes, else exit.
 */

