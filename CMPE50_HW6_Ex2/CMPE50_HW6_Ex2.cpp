//============================================================================
// Name : CMPE50_HW6_Ex2.cpp
// Author : Hemang Mehra
// Description : The output of HW6 exercise 2
//============================================================================

#include <iostream>
#include <string>

using namespace std;

class Duple {
public:
    Duple();
    Duple(int first, int second);
    friend istream& operator >>(istream& ins, Duple& second);
    friend ostream& operator <<(ostream& outs, Duple& second);
    friend Duple operator +(const Duple& first, const Duple& second);
    friend Duple operator -(const Duple& first, const Duple& second);
private:
    int f;
    int s;
};

int main() {
    Duple d1, d2(3, 4), result;

    cout << "Enter duple (format: (x, y)): ";
    cin >> d1;

    cout << "First duple (d1): " << d1 << endl;
    cout << "Second duple (d2): " << d2 << endl;

    result = d1 + d2;
    cout << "The sum of the duples is: " << result << endl;

    result = d1 - d2;
    cout << "The difference of the duples is: " << result << endl;

    return 0;
}


Duple::Duple() {
    f = 0;
    s = 0;
}

Duple::Duple(int first, int second) {
    f = first;
    s = second;
}

istream& operator >>(istream& ins, Duple& second) {
    string input;
    getline(ins, input, '(');
    getline(ins, input, ',');
    second.f = stoi(input);
    getline(ins, input, ')');
    second.s = stoi(input);
    return ins;
}

ostream& operator <<(ostream& outs, Duple& second) {
    outs << "(" << second.f << ", " << second.s << ")";
    return outs;
}

Duple operator +(const Duple& first, const Duple& second) {
    return Duple(first.f + second.f, first.s + second.s);
}

Duple operator -(const Duple& first, const Duple& second) {
    return Duple(first.f - second.f, first.s - second.s);
}

/* OUTPUT:

Enter duple (format: (x, y)): (-10,12)
First duple (d1): (-10, 12)
Second duple (d2): (3, 4)
The sum of the duples is: (-7, 16)
The difference of the duples is: (-13, 8)

Process finished with exit code 0
*/