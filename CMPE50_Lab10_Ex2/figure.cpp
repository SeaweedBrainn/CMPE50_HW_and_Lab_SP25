//
// Created by Hemang Mehra on 4/22/25.
//

#include "figure.h"
#include <iostream>
using namespace std;

void figure::draw() {
    cout << "Drawing a figure." << endl;
}
void figure::erase() {
    cout << "Erasing a figure." << endl;
}
void figure::center() {
    cout << "********\nCentering a figure: " << endl;
    erase();
    draw();
    cout << "********" << endl;
}