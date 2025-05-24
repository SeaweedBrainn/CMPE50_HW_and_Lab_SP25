//
// Created by Hemang Mehra on 5/2/25.
//

#ifndef MANAGER_H
#define MANAGER_H
#include "salariedemployee.h"


class Manager : public SalariedEmployee
{
public:
    Manager();
    Manager(const Manager& m);
    ~Manager();
    void add_report(const SalariedEmployee& e);
    Manager& operator=(const Manager& m);
    friend ostream& operator<<(ostream& ost, const Manager& m);
private:
    SalariedEmployee* reports;
    int noReport;
};



#endif //MANAGER_H
