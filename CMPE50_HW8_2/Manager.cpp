//
// Created by Hemang Mehra on 5/2/25.
//

#include "Manager.h"
#include <iostream>
using namespace std;

Manager::Manager() : SalariedEmployee(), reports(nullptr), noReport(0) {
}

Manager::Manager(const Manager& m) : SalariedEmployee(m), noReport(m.noReport) {
    reports = new SalariedEmployee[noReport];
    for (int i = 0; i < noReport; i++) {
        reports[i] = m.reports[i];
    }
}

Manager::~Manager() {
    delete[] reports;
    reports = nullptr;
}

void Manager::add_report(const SalariedEmployee& e) {
    SalariedEmployee* temp = new SalariedEmployee[noReport + 1];
    for (int i = 0; i < noReport; i++) {
        temp[i] = reports[i];
    }
    temp[noReport] = e;
    delete[] reports;
    reports = temp;
    noReport++;
}

Manager& Manager::operator=(const Manager &m) {
    if (this == &m) {
        return *this;
    }
    SalariedEmployee::operator=(m);
    delete[] reports;
    noReport = m.noReport;
    reports = new SalariedEmployee[noReport];
    for (int i = 0; i < noReport; i++) {
        reports[i] = m.reports[i];
    }
    return *this;
}

ostream& operator<<(ostream& ost, const Manager& m) {
    ost << "Manager Name: " << m.get_name() << endl;
    ost << "Manager SSN: " << m.get_ssn() << endl;
    ost << "Manager Salary: " << m.get_salary() << endl;
    ost << "Reports:" << endl;
    for (int i = 0; i < m.noReport; i++) {
        ost << m.reports[i].get_name() << " $" << m.reports[i].get_salary() << endl;
    }
    return ost;
}

