//
// Created by Hemang Mehra on 5/2/25.
//

#ifndef PET_H
#define PET_H
#include <iostream>
#include <string>
using namespace std;

class Pet {
public:
    Pet();
    Pet(string name, int age, string* visits_dates, int num_visits);
    Pet(const Pet& other);
    virtual ~Pet();

    string get_name() const;
    int get_age() const;
    string* get_visits() const;
    int get_visit_count() const;

    void set_name(const string& name);
    void set_age(int age);
    void set_visits(const string* visits_dates, int count);
    void add_visit(const string& visit_date);

    virtual void print() const;
    Pet& operator=(const Pet& other);
protected:
    string name;
    int age;
    string* visits;
    int num_visits;
};



#endif //PET_H
