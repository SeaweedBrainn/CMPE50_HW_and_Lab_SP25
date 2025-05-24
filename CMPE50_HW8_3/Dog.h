//
// Created by Hemang Mehra on 5/2/25.
//

#ifndef DOG_H
#define DOG_H
#include "Pet.h"
#include <iostream>
#include <string>
using namespace std;

class Dog : public Pet {
public:
    Dog();
    Dog(string name, int age, string* visits_dates, int num_visits, string breed_name, string* shots_dates, int num_shots);
    Dog(const Dog& other);
    virtual ~Dog();


    string get_breed() const;
    string* get_shots() const;
    int get_shot_count() const;

    void set_breed(const string& breed);
    void set_shots(const string* shots, int count);
    void add_shot(const string& shot_date);

    virtual void print() const;
    Dog& operator=(const Dog& other);
private:
    string breed;
    string* shots;
    int num_shots;
};



#endif //DOG_H
