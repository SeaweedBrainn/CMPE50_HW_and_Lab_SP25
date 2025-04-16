//============================================================================
// Name : CMPE50_Lab6_Ex3.cpp
// Author : Hemang Mehra
// Description : The output of Lab 6 exercise 3
//============================================================================

#include <iostream>
using namespace std;

class Parallelogram {
    public:
        Parallelogram();
        Parallelogram(double b, double h);
        void calculate();
        void display();
    private:
        double base, height, area;
};

int main()
{
    double b, h;
    cout << "Enter length of base of parallelogram: ";
    cin >> b;
    cout << "Enter height of parallelogram: ";
    cin >> h;

    Parallelogram par(b, h); //object created
    par.calculate(); //calling function
    par.display(); //calling function
    return 0;
}

Parallelogram::Parallelogram() {
    base = height = 0;
}

Parallelogram::Parallelogram(double b, double h) {
    base = b;
    height = h;
}

void Parallelogram::calculate() {
    area = base*height;
}

void Parallelogram::display() {
    cout << "The area of parallelogram is " << area << " squared units" << endl;
}



/* OUTPUT:
Enter length of base of parallelogram: 10
Enter height of parallelogram: 20
The area of parallelogram is 200 squared units

Process finished with exit code 0
*/