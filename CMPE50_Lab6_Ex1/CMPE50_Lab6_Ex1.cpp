//============================================================================
// Name : CMPE50_Lab6_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of Lab 6 exercise 1
//============================================================================

#include <algorithm>
#include <iostream>
using namespace std;

class Record {
    public:
        Record();
        void set(int q1, int q2, int q3, int m, int f);
        double getWeightedAverage();
    private:
        void calculate();
        int quiz1, quiz2, quiz3, midterm, final;
        double weightedAverage;
};

int main()
{
    Record studentRecord1;
    Record studentRecord2;

    studentRecord1.set(10, 6, 8, 80, 90);
    studentRecord2.set(0, 0, 5, 100, 50);

    cout << "Weighted Average for first set of scores is: " << studentRecord1.getWeightedAverage() << endl;
    cout << "Weighted Average for second set of scores is: " << studentRecord2.getWeightedAverage() << endl;
}

void Record::set(int q1, int q2, int q3, int m, int f) {
    quiz1 = q1; quiz2 = q2; quiz3 = q3;
    midterm = m;
    final = f;

    calculate();
}

void Record::calculate() {
    int q = min(quiz1, min(quiz2, quiz3));
    weightedAverage = ((quiz1 + quiz2 + quiz3 - q)/ 20.0 * 0.25 + midterm / 100.0 * 0.25 + final / 100.0 * 0.5)*100;
}

double Record::getWeightedAverage() {
    return weightedAverage;
}

Record::Record() {
    quiz1 = quiz2 = quiz3 = midterm = final = 0;
    weightedAverage = 0.0;
}

/* Input 1: q1 = 10, q2 = 6, q3 = 8, m = 80, f = 90
 * Output 1: Weighted Average for first set of scores is: 87.5
 *
 * Input 2: q1 = 0, q2 = 0, q3 = 5, m = 100, f = 50
 * Output 2: Weighted Average for second set of scores is: 56.25
 */