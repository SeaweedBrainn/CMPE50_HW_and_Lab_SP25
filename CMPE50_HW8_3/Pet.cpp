//
// Created by Hemang Mehra on 5/2/25.
//

#include "Pet.h"

Pet::Pet() : name(""), age(0), visits(nullptr), num_visits(0) {}

Pet::Pet(string name, int age, string* visits_dates, int num_visits)
    : name(name), age(age), num_visits(num_visits) {
    visits = new string[num_visits];
    for (int i = 0; i < num_visits; ++i) {
        visits[i] = visits_dates[i];
    }
}

Pet::Pet(const Pet& other)
    : name(other.name), age(other.age), num_visits(other.num_visits) {
    visits = new string[num_visits];
    for (int i = 0; i < num_visits; ++i) {
        visits[i] = other.visits[i];
    }
}

Pet::~Pet() {
    delete[] visits;
}

string Pet::get_name() const {
    return name;
}

int Pet::get_age() const {
    return age;
}

string* Pet::get_visits() const {
    return visits;
}

int Pet::get_visit_count() const {
    return num_visits;
}

void Pet::set_name(const string& name) {
    this->name = name;
}

void Pet::set_age(int age) {
    this->age = age;
}

void Pet::set_visits(const string* visits_dates, int count) {
    delete[] visits;
    num_visits = count;
    visits = new string[num_visits];
    for (int i = 0; i < num_visits; ++i) {
        visits[i] = visits_dates[i];
    }
}

void Pet::add_visit(const string& visit_date) {
    string* new_visits = new string[num_visits + 1];
    for (int i = 0; i < num_visits; ++i) {
        new_visits[i] = visits[i];
    }
    new_visits[num_visits] = visit_date;
    delete[] visits;
    visits = new_visits;
    num_visits++;
}

void Pet::print() const {
    cout << "Pet Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Visits: ";
    for (int i = 0; i < num_visits; ++i) {
        cout << visits[i] << " ";
    }
    cout << endl;
}

Pet& Pet::operator=(const Pet& other) {
    if (this == &other) {
        return *this;
    }
    delete[] visits;
    name = other.name;
    age = other.age;
    num_visits = other.num_visits;
    visits = new string[num_visits];
    for (int i = 0; i < num_visits; ++i) {
        visits[i] = other.visits[i];
    }
    return *this;
}

