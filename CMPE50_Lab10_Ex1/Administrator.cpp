//
// Created by Hemang Mehra on 4/22/25.
//
#include <iostream>
#include <string>
#include <cctype>
#include "Administrator.h"
using namespace std;

Administrator::Administrator() : SalariedEmployee(), title(""), responsibility(""), supervisor("")
{}

Administrator::Administrator(string the_name, string the_ssn,
                               double the_weekly_salary, string the_title,
                               string the_responsibility, string the_supervisor)
                                   : SalariedEmployee(the_name, the_ssn, the_weekly_salary),
                                     title(the_title), responsibility(the_responsibility),
                                     supervisor(the_supervisor)
{}

void Administrator::set_supervisor(string new_supervisor)
{
    supervisor = new_supervisor;
}

void Administrator::read_admin_data()
{
    cout << "Enter the name of the administrator: ";
    string name;
    getline(cin, name);
    set_name(name);

    cout << "Enter the SSN of the administrator: ";
    string ssn;
    cin >> ssn;
    set_ssn(ssn);

    cout << "Enter the weekly salary of the administrator: ";
    double salary;
    cin >> salary;
    set_salary(salary);
    new_line();

    cout << "Enter the title of the administrator: ";
    getline(cin, title);

    cout << "Enter the responsibility of the administrator: ";
    getline(cin, responsibility);

    cout << "Enter the supervisor of the administrator: ";
    getline(cin, supervisor);
}

void Administrator::print()
{
    cout << "Administrator Name: " << get_name() << endl;
    cout << "SSN: " << get_ssn() << endl;
    cout << "Weekly Salary: " << get_salary() << endl;
    cout << "Title: " << title << endl;
    cout << "Responsibility: " << responsibility << endl;
    cout << "Supervisor: " << supervisor << endl;
}

void Administrator::print_check()
{
    set_net_pay(get_salary());
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of " << get_name() << endl;
    cout << "The sum of " << get_net_pay() << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << get_ssn() << endl;
    cout << "Administrator. Regular Pay: "
         << get_salary() << endl;
    cout << "Title: " << title << endl;
    cout << "Responsibility: " << responsibility << endl;
    cout << "Supervisor: " << supervisor << endl;
    cout << "_________________________________________________\n";
}

void Administrator::new_line() {
    while (cin.get() != '\n'){}
}