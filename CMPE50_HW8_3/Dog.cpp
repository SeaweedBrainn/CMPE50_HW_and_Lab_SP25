//
// Created by Hemang Mehra on 5/2/25.
//

#include "Dog.h"

Dog::Dog() : Pet(), breed(""), shots(nullptr), num_shots(0) {}

Dog::Dog(string name, int age, string* visits_dates, int num_visits, string breed_name, string* shots_dates, int num_shots)
    : Pet(name, age, visits_dates, num_visits), breed(breed_name), num_shots(num_shots) {
    shots = new string[num_shots];
    for (int i = 0; i < num_shots; ++i) {
        shots[i] = shots_dates[i];
    }
}

Dog::Dog(const Dog& other)
    : Pet(other), breed(other.breed), num_shots(other.num_shots) {
    shots = new string[num_shots];
    for (int i = 0; i < num_shots; ++i) {
        shots[i] = other.shots[i];
    }
}

Dog::~Dog() {
    delete[] shots;
}

string Dog::get_breed() const {
    return breed;
}

string* Dog::get_shots() const {
    return shots;
}

int Dog::get_shot_count() const {
    return num_shots;
}

void Dog::set_breed(const string& breed) {
    this->breed = breed;
}

void Dog::set_shots(const string* shots_dates, int count) {
    delete[] shots;
    num_shots = count;
    shots = new string[num_shots];
    for (int i = 0; i < num_shots; ++i) {
        shots[i] = shots_dates[i];
    }
}

void Dog::add_shot(const string& shot_date) {
    string* new_shots = new string[num_shots + 1];
    for (int i = 0; i < num_shots; ++i) {
        new_shots[i] = shots[i];
    }
    new_shots[num_shots] = shot_date;
    delete[] shots;
    shots = new_shots;
    num_shots++;
}

void Dog::print() const {
    Pet::print(); //I also called the print function of the pet class here
    cout << "Breed: " << breed << endl;
    cout << "Shots: ";
    for (int i = 0; i < num_shots; ++i) {
        cout << shots[i] << " ";
    }
    cout << endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this == &other) {
        return *this;
    }

    Pet::operator=(other);
    breed = other.breed;
    delete[] shots;
    num_shots = other.num_shots;
    shots = new string[num_shots];
    for (int i = 0; i < num_shots; ++i) {
        shots[i] = other.shots[i];
    }
    return *this;
}