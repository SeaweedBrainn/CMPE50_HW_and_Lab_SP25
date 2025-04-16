//============================================================================
// Name : CMPE50-HW-1-2.cpp
// Author : Hemang Mehra
// Description : The output of HW 1 exercise 2
//============================================================================

#include <iostream>
using namespace std;

void displayMenu(double reqMoney);
bool isMoneyRemaining(double totalMoney, double reqMoney);
void assignNextCoin(int& nextCoin);
void calcTotalMoney(double& totalMoney, int nextCoin);
double calcChange(double totalMoney, double reqMoney);

int main() {
    const double reqMoney = 3.50;
    int nextCoin;
    double totalMoney = 0;

    displayMenu(reqMoney);

    while (isMoneyRemaining(totalMoney, reqMoney)) {
        assignNextCoin(nextCoin);
        calcTotalMoney(totalMoney, nextCoin);
    }
    cout << "Enjoy your deep-fried twinkie" << endl;
    cout << "Your change is $" << calcChange(totalMoney, reqMoney) << endl;
}
void displayMenu(double reqMoney) {
    cout << "Buy a deep-fried twinkie for $" << reqMoney << endl;
    cout << "Enter 0 to insert a nickel." << endl;
    cout << "Enter 1 to insert a dime." << endl;
    cout << "Enter 2 to insert a quarter." << endl;
    cout << "Enter 3 to insert a dollar.\n" << endl;
}

bool isMoneyRemaining(double totalMoney, double reqMoney) {
    return totalMoney < reqMoney;
}

void assignNextCoin(int& nextCoin) {
    cout << "Insert coin: ";
    cin >> nextCoin;
    while (nextCoin < 0 || nextCoin > 3) {
        cout << "Please enter correct coin choice (0 -> nickel ,1 -> dime,2 -> quarter,3 -> dollar): ";
        cin >> nextCoin;
    }
}

void calcTotalMoney(double& totalMoney, int nextCoin) {
    if (nextCoin == 0) totalMoney += 0.05;
    else if (nextCoin == 1) totalMoney += 0.10;
    else if (nextCoin == 2) totalMoney += 0.25;
    else if (nextCoin == 3) totalMoney += 1.00;
    cout << "Money inserted till now is $" << totalMoney << "\n" << endl;
}

double calcChange(double totalMoney, double reqMoney) {
    return totalMoney - reqMoney;
}

/* OUTPUT:
 * Buy a deep-fried twinkie for $3.5
 * Enter 0 to insert a nickel.
 * Enter 1 to insert a dime.
 * Enter 2 to insert a quarter.
 * Enter 3 to insert a dollar.
 *
 * Insert coin: 3
 * Money inserted till now is $1
 *
 * Insert coin: -1
 * Please enter correct coin choice (0 -> nickel ,1 -> dime,2 -> quarter,3 -> dollar): 4
 * Please enter correct coin choice (0 -> nickel ,1 -> dime,2 -> quarter,3 -> dollar): 1
 * Money inserted till now is $1.1
 *
 * Insert coin: 2
 * Money inserted till now is $1.35
 *
 * Insert coin: 0
 * Money inserted till now is $1.4
 *
 * Insert coin: 1
 * Money inserted till now is $1.5
 *
 * Insert coin: 3
 * Money inserted till now is $2.5
 *
 * Insert coin: 2
 * Money inserted till now is $2.75
 *
 * Insert coin: 1
 * Money inserted till now is $2.85
 *
 * Insert coin: 3
 *
 * Money inserted till now is $3.85
 *
 * Enjoy your deep-fried twinkie
 * Your change is $0.35
 *
 * Process finished with exit code 0
 * /