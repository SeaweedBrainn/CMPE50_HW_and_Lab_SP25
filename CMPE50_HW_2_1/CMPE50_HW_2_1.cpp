//============================================================================
// Name : CMPE50-HW-2-1.cpp
// Author : Hemang Mehra
// Description : The output of HW 2 exercise 1
//============================================================================

#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

void avgStdDev(double s1, double s2, double s3, double s4, double &average, double &stdDev);
double avg(double s1, double s2, double s3, double s4);
double stdDev(double s1, double s2, double s3, double s4, double average);
void new_line();

int main()
{
    char repeat = 'y';
    while (tolower(repeat) == 'y') {
        double s1, s2, s3, s4;
        double average, stdDeviation;
        cout << "Enter four numbers to calculate mean and standard deviation: ";
        cin >> s1 >> s2 >> s3 >> s4;
        new_line(); // I put this here in case user inputs more than four integers then than would mess with the repeat line
        avgStdDev(s1, s2, s3, s4, average, stdDeviation);
        cout << "Average = " << average << endl;
        cout << "Standard Deviation = " << stdDeviation << endl;
        cout << endl;
        cout << "Do you want to run the calculations again?(y/n): ";
        cin >> repeat;
        new_line();
        cout << endl;
    }
}

void avgStdDev(double s1, double s2, double s3, double s4, double &average, double &stdDeviation) {
    average = avg(s1, s2, s3, s4);
    stdDeviation = stdDev(s1, s2, s3, s4, average);
}

double avg(double s1, double s2, double s3, double s4) {
    return (s1 + s2 + s3 + s4)/4;
}

double stdDev(double s1, double s2, double s3, double s4, double average) {
    double numArr[] = {s1, s2, s3, s4};
    for (int i = 0; i < 4; i++) {
        numArr[i] = pow(numArr[i] - average, 2);
    }
    return sqrt(avg(numArr[0], numArr[1], numArr[2], numArr[3]));
}

void new_line() {
    while (cin.get() != '\n') {
    }
}
/* OUTPUT:
Enter four numbers to calculate mean and standard deviation: 0 1 1 2
Average = 1
Standard Deviation = 0.707107

Do you want to run the calculations again?(y/n): yes

Enter four numbers to calculate mean and standard deviation: 3 5 8 13
Average = 7.25
Standard Deviation = 3.76663

Do you want to run the calculations again?(y/n): y

Enter four numbers to calculate mean and standard deviation: 21 34 55 89
Average = 49.75
Standard Deviation = 25.7038

Do you want to run the calculations again?(y/n): YES

Enter four numbers to calculate mean and standard deviation: 144 233 377 610
Average = 341
Standard Deviation = 176.16

Do you want to run the calculations again?(y/n): Y

Enter four numbers to calculate mean and standard deviation: 987 1597 2584 4181
Average = 2337.25
Standard Deviation = 1207.42

Do you want to run the calculations again?(y/n): n


Process finished with exit code 0
*/