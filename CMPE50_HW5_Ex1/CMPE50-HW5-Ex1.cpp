//============================================================================
// Name : CMPE50_HW5_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of HW5 exercise 1
//============================================================================

#include <iostream>
using namespace std;

class CDAccount {
public:
    CDAccount();
    CDAccount(double bal, double i_rate, int trm);
    void set_data(double bal, double i_rate, int trm);
    double get_initBalance();
    double get_finalBalance();
    double get_rate();
    int get_term();
private:
    double balance, interest_rate;
    int term;
};

int main()
{
    CDAccount account1, account2(1000,10,2);

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << "For default constructor account 1:\nInitial Balance = $" << account1.get_initBalance()
    << "\nInterest Rate = " << account1.get_rate() << "% per annum"
    << "\nTerm = " << account1.get_term() << " month(s)";

    cout << endl << endl;

    cout << "For (1000,10,2) constructor account 2:\nInitial Balance = $" << account2.get_initBalance()
    << "\nInterest Rate = " << account2.get_rate() << "% per annum"
    << "\nTerm = " << account2.get_term() << " month(s)";

    cout << endl << endl;

    account1.set_data(1200.50,25,6);
    cout << "After setting (1200.50,25,6) in account 1:\nInitial Balance = $" << account1.get_initBalance()
    << "\nInterest Rate = " << account1.get_rate() << "% per annum"
    << "\nTerm = " << account1.get_term() << " month(s)";

    cout << endl << endl;

    cout << "Final Balance for account 1 (1200.50, 25, 6) = $" << account1.get_finalBalance() << endl;
    cout << "Final Balance for account 2 (1000.00, 10, 2) = $" << account2.get_finalBalance() << endl;
}

void CDAccount::set_data(double bal, double i_rate, int trm) {
    balance = bal;
    interest_rate = i_rate;
    term = trm;
}

double CDAccount::get_initBalance() {
    return balance;
}

double CDAccount::get_finalBalance() {
    double bal = (balance * (interest_rate) * (term/12.0))/100 + balance;
    return bal;
}

double CDAccount::get_rate() {
    return interest_rate;
}

int CDAccount::get_term() {
    return term;
}

CDAccount::CDAccount() {
    set_data(0,0,0);
}

CDAccount::CDAccount(double bal, double i_rate, int trm) {
    set_data(bal,i_rate,trm);
}


/* OUTPUT:

For default constructor account 1:
Initial Balance = $0.00
Interest Rate = 0.00% per annum
Term = 0 month(s)

For (1000,10,2) constructor account 2:
Initial Balance = $1000.00
Interest Rate = 10.00% per annum
Term = 2 month(s)

After setting (1200.50,25,6) in account 1:
Initial Balance = $1200.50
Interest Rate = 25.00% per annum
Term = 6 month(s)

Final Balance for account 1 (1200.50, 25, 6) = $1350.56
Final Balance for account 2 (1000.00, 10, 2) = $1016.67

Process finished with exit code 0

 */