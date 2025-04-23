//============================================================================
// Name : CMPE50_Lab10_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of Lab10 exercise 1.
//============================================================================

#include <iostream>
#include "administrator.h"
#include <string>
using namespace std;

int main()
{
    Administrator admin;

    admin.read_admin_data();
    cout << endl;

    admin.print();
    cout << endl;

    cout << "Set a different supervisor for the administrator: ";
    string new_supervisor;
    getline(cin,new_supervisor);
    admin.set_supervisor(new_supervisor);
    cout << endl;

    admin.print_check();

    return 0;
}

/* Output:
* Enter the name of the administrator: The Doctor
Enter the SSN of the administrator: 01-100-0101
Enter the weekly salary of the administrator: 7777.77
Enter the title of the administrator: Time Lord
Enter the responsibility of the administrator: Duty of Care
Enter the supervisor of the administrator: Melody Pond

Administrator Name: The Doctor
SSN: 01-100-0101
Weekly Salary: 7777.77
Title: Time Lord
Responsibility: Duty of Care
Supervisor: Melody Pond

Set a different supervisor for the administrator: River Song


__________________________________________________
Pay to the order of The Doctor
The sum of 7777.77 Dollars
_________________________________________________
Check Stub NOT NEGOTIABLE
Employee Number: 01-100-0101
Administrator. Regular Pay: 7777.77
Title: Time Lord
Responsibility: Duty of Care
Supervisor: River Song
_________________________________________________

Process finished with exit code 0
*/