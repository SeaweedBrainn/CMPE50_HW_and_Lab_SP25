//============================================================================
// Name : CMPE50_Lab6_Ex2.cpp
// Author : Hemang Mehra
// Description : The output of Lab 6 exercise 2
//============================================================================

#include <iostream>
using namespace std;

class Counter {
public:
    Counter();
    Counter(int n);
    void increment();
    void decrement();
    int currentCount();
private:
    int count;
};

int main()
{
    Counter num1;
    Counter num2(4);

    cout << "Initialize num1 with default constructor: " << num1.currentCount() << endl;
    cout << "Initialize num2 with constructor argument: " << num2.currentCount() << endl << endl;

    num1.increment();
    num2.increment();

    cout << "Value of num1 after incrementing: " << num1.currentCount() << endl;
    cout << "Value of num2 after incrementing: " << num2.currentCount() << endl << endl;

    num1.decrement();
    num1.decrement(); //Should say error and set it to 0

    num2.decrement();
    num2.decrement();

    cout << "Value of num1 after decrementing twice: " << num1.currentCount() << endl;
    cout << "Value of num2 after decrementing twice: " <<num2.currentCount() << endl << endl;

}

Counter::Counter() {
    count = 0;
}

Counter::Counter(int n) {
    if (n == 0) cout << "Be careful, the count is set to 0" << endl;
    count = n;

    if (count < 0) {
        count = 0;
        cout << "Count cannot be negative, it is set to 0" << endl;
    }
}

void Counter::increment() {
    count++;
}

void Counter::decrement() {
    count--;
    if (count == 0) cout << "Be careful, the count is now 0" << endl;

    if (count < 0) {
        count = 0;
        cout << "Count cannot be negative, it is set to 0" << endl;
    }
}

int Counter::currentCount() {
    return count;
}

/* OUTPUT:
Initialize num1 with default constructor: 0
Initialize num2 with constructor argument 4: 4

Value of num1 after incrementing: 1
Value of num2 after incrementing: 5

Be careful, the count is now 0
Count cannot be negative, it is set to 0
Value of num1 after decrementing twice: 0
Value of num2 after decrementing twice: 3


Process finished with exit code 0
*/