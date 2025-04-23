//
// Created by Hemang Mehra on 4/22/25.
//

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "salariedemployee.h"
#include <string>

class Administrator: public SalariedEmployee
{
public:
    Administrator();
    Administrator(string the_name, string the_ssn,
                  double the_weekly_salary, string the_title,
                  string the_responsibility, string the_supervisor);
    void set_supervisor(string new_supervisor);
    void read_admin_data();
    void print();
    void print_check();
private:
    string title, responsibility, supervisor;
    void new_line();
};

#endif //ADMINISTRATOR_H
