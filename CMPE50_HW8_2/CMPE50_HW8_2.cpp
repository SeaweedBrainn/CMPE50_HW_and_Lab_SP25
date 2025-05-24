//============================================================================
// Name : CMPE50_HW8_Ex2.cpp
// Author : Hemang Mehra
// Description : The output of HW8 exercise 2.
//============================================================================

#include <iostream>
#include "manager.h"
using namespace std;

int main() {
    Manager m1;
    cout << "Default Manager:\n" << m1 << endl;

    SalariedEmployee e1("Alice Smith", "111-11-1111", 1200.00);
    SalariedEmployee e2("Bob Johnson", "222-22-2222", 1100.00);

    m1.add_report(e1);
    m1.add_report(e2);
    cout << "Manager after adding two reports:\n" << m1 << endl;

    Manager m2(m1);
    cout << "Copy constructed Manager:\n" << m2 << endl;

    Manager m3;
    m3 = m1;
    cout << "Assigned Manager:\n" << m3 << endl;

    return 0;
}

/* OUTPUT:
Default Manager:
Manager Name: No name yet
Manager SSN: No number yet
Manager Salary: 0
Reports:

Manager after adding two reports:
Manager Name: No name yet
Manager SSN: No number yet
Manager Salary: 0
Reports:
Alice Smith $1200
Bob Johnson $1100

Copy constructed Manager:
Manager Name: No name yet
Manager SSN: No number yet
Manager Salary: 0
Reports:
Alice Smith $1200
Bob Johnson $1100

Assigned Manager:
Manager Name: No name yet
Manager SSN: No number yet
Manager Salary: 0
Reports:
Alice Smith $1200
Bob Johnson $1100


Process finished with exit code 0
*/