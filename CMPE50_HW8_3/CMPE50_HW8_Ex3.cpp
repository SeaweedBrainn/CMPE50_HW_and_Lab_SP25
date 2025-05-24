//============================================================================
// Name : CMPE50_HW8_Ex3.cpp
// Author : Hemang Mehra
// Description : The output of HW8 exercise 3.
//============================================================================

#include <iostream>
#include "Dog.h"

using namespace std;

void PrintBill(const Pet& pet) {
    pet.print();
}

int main() {
    string visits1[] = {"01/02/2024", "03/15/2024"};
    string shots1[] = {"02/01/2024", "04/10/2024"};

    Dog d1("Buddy", 5, visits1, 2, "Golden Retriever", shots1, 2);
    cout << "Original Dog:" << endl;
    PrintBill(d1);

    Dog d2(d1);
    cout << "\nCopy Constructed Dog:" << endl;
    PrintBill(d2);

    Dog d3;
    d3 = d1;
    cout << "\nAssigned Dog:" << endl;
    PrintBill(d3);

    return 0;
}

/* OUPUT
Original Dog:
Pet Name: Buddy
Age: 5
Visits: 01/02/2024 03/15/2024
Breed: Golden Retriever
Shots: 02/01/2024 04/10/2024

Copy Constructed Dog:
Pet Name: Buddy
Age: 5
Visits: 01/02/2024 03/15/2024
Breed: Golden Retriever
Shots: 02/01/2024 04/10/2024

Assigned Dog:
Pet Name: Buddy
Age: 5
Visits: 01/02/2024 03/15/2024
Breed: Golden Retriever
Shots: 02/01/2024 04/10/2024

Process finished with exit code 0
*/