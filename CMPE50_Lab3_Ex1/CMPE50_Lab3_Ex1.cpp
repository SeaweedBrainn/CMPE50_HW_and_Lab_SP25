//============================================================================
// Name        : CMPE50_Lab3_Ex1.cpp
// Author      : Hemang Mehra
// Description : The output of lab exercise 3.1
//============================================================================

#include <iomanip>
#include <iostream>
using namespace std;

void getGrades(double emptyArr[][5]);
void displayGrades(double Grades[][5]);
void findBest(double Grades[][5], double bestGrade[]);
void findWorse(double Grades[][5], double worstGrade[]);
void findAvg(double Grades[][5], double avgGrade[]);
void overallAvg(double Grades[][5], double avgGrades[], double& overallAvg);
bool isFailing(double avgGrade[]);
void failingReason(double avgGrades[]);

int main() {
    double Grades[2][5];
    getGrades(Grades);
    displayGrades(Grades);
}

void getGrades(double Grades[][5]) {
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 5; col++) {
            if (row == 0) cout << "Enter HW grade " << col+1 << ": ";
            else cout << "Enter lab grade " << col+1 << ": ";
            cin >> Grades[row][col];
        }
    }
}

void findBest(double Grades[][5], double bestGrade[] ) {
    for (int row = 0; row < 2; row++) {
        bestGrade[row] = Grades[row][0];
        for (int col = 0; col < 5; col++) {
            if (Grades[row][col] > bestGrade[row]) bestGrade[row] = Grades[row][col];
        }
    }
}

void findWorse(double Grades[][5], double worstGrade[]) {
    for (int row = 0; row < 2; row++) {
        worstGrade[row] = Grades[row][0];
        for (int col = 0; col < 5; col++) {
            if (Grades[row][col] < worstGrade[row]) worstGrade[row] = Grades[row][col];
        }
    }
}

void findAvg(double Grades[][5], double avgGrade[]) {
    for (int row = 0; row < 2; row++) {
        double sum = 0;
        for (int col = 0; col < 5; col++) {
            sum += Grades[row][col];
        }
        avgGrade[row] = sum / 5;
    }
}

void overallAvg(double Grades[][5], double avgGrade[], double& overallAvg) {
    double sum = 0;
    for (int col = 0; col < 5; col++) {
        avgGrade[col] = (Grades[0][col] + Grades[1][col])/2;
        sum += avgGrade[col];
    }
    overallAvg = sum / 5;
}

bool isFailing(double avgGrades[]) {
    if (avgGrades[0] < 50 || avgGrades[1] < 50) return true;
    return false;
}
void failingReason(double avgGrades[]) {
    if (avgGrades[0] < 50 && avgGrades[1] < 50) {
        cout << "I’m sorry to inform you that you failed the class, because your performance in both HW and lab was <50%. Try again next semester." << endl;
    }
    else if (avgGrades[0] < 50) {
        cout << "I’m sorry to inform you that you failed the class, because your performance in HW was <50%. Try again next semester." << endl;
    }
    else if (avgGrades[1] < 50) {
        cout << "I’m sorry to inform you that you failed the class, because your performance in the lab was <50%. Try again next semester." << endl;
    }
}

void displayGrades(double Grades[][5]) {
    double bestGrade[2], worstGrade[2], avgGrade[2];
    double avgGrades[5];
    double overallAvgVar;
    findBest(Grades, bestGrade);
    findWorse(Grades, worstGrade);
    findAvg(Grades, avgGrade);
    overallAvg(Grades, avgGrades, overallAvgVar);

    cout << "        1        2       3       4       5     BEST    WORST   AVG" << endl;
    cout << "     **************************************************************" << endl;
    cout << endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    for (int row = 0; row < 2; row++) {
        if (row == 0) cout << "HW   ";
        else cout << "Lab  ";
        for (int col = 0; col < 5; col++) {
            cout.width(7);
            cout << Grades[row][col] << " ";
        }
        cout << setw(7) << bestGrade[row] << setw(7) << worstGrade[row] << setw(7) << avgGrade[row] << endl;
    }
    cout << endl;
    cout << "Avg  ";
    for (int col = 0; col < 5; col++) {
        cout.width(7);
        cout << avgGrades[col] << " ";
    }
    cout << "   Overall: " <<setw(7) << overallAvgVar << endl;
    cout << endl;

    if (!isFailing(avgGrade)) cout << "Congratulations! You passed the class!" << endl;
    else failingReason(avgGrade);
}

/* OUTPUT:
Enter HW grade 1: 100
Enter HW grade 2: 90
Enter HW grade 3: 80
Enter HW grade 4: 100
Enter HW grade 5: 100
Enter lab grade 1: 100
Enter lab grade 2: 100
Enter lab grade 3: 70
Enter lab grade 4: 60
Enter lab grade 5: 90

1        2       3       4       5     BEST    WORST   AVG
**************************************************************
HW    100.00   90.00   80.00  100.00  100.00  100.00  80.00  94.00
Lab   100.00  100.00   70.00   60.00   90.00  100.00  60.00  84.00

Avg   100.00   95.00   75.00   80.00   95.00    Overall:   89.00

Congratulations! You passed the class!

Process finished with exit code 0
*/