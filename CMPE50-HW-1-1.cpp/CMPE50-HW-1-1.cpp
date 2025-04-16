//============================================================================
// Name : CMPE50-HW-1-1.cpp
// Author : Hemang Mehra
// Description : The output of HW 1 exercise 1
//============================================================================

#include <iostream>
using namespace std;

double calcHatSize(double height, double weight);
double calcJacketSize(double height, double weight, int age);
double calcWaist(double weight, int age);

int main() {
    char repeat = 'y';
    while (repeat == 'y') {
        double height, weight;
        int age;
        cout << "Enter your height (in inches): ";
        cin >> height;
        cout << "Enter your weight (in pounds): ";
        cin >> weight;
        cout << "Enter your age: ";
        cin >> age;
        cout << "\nHat Size: " << calcHatSize(height, weight) << endl;
        cout << "Jacket Size: " << calcJacketSize(height, weight, age) << endl;
        cout << "Waist: " << calcWaist(weight, age) << endl;
        cout << "\n Do you want to run the calculations again? (y/n): ";
        cin >> repeat;
        cout << endl;
    }
    return 0;
}

double calcHatSize(double height, double weight) {
    return 2.9*weight/height;
}

double calcJacketSize(double height, double weight, int age) {
    int ageFactor = 0;
    for (int i = 40; i <= age; i = i+10) {
        ageFactor++;
    }
    return height*weight/288 + ageFactor/8.0;
}

double calcWaist(double weight, int age) {
    int ageFactor = 0;
    for (int i = 30; i <= age; i = i+2) {
        ageFactor++;
    }
    return weight/5.7 + ageFactor/10.0;
}

/* OUTPUT:
 * Enter your height (in inches): 66
 * Enter your weight (in pounds): 160
 * Enter your age: 20
 *
 * Hat Size: 7.0303
 * Jacket Size: 36.6667
 * Waist: 28.0702
 *
 *  Do you want to run the calculations again? (y/n): y
 *
 * Enter your height (in inches): 80
 * Enter your weight (in pounds): 190
 * Enter your age: 25
 *
 * Hat Size: 6.8875
 * Jacket Size: 52.7778
 * Waist: 33.3333
 *
 *  Do you want to run the calculations again? (y/n): n
 *
 *
 * Process finished with exit code 0
 */