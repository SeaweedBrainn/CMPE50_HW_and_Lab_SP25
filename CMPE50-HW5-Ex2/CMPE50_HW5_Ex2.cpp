//============================================================================
// Name : CMPE50_HW5_Ex2.cpp
// Author : Hemang Mehra
// Description : The output of HW5 exercise 2
//============================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Month {
public:
    Month();
    Month(string month);
    void setMonth(istream &f);
    void getMonthN(ostream &f);
    void getMonthString(ostream &f);
    Month nextMonth();
private:
    int find_monthno(string month);
    string find_monthstr(int n);
    int month_no;
};

int main() {
    Month m1;
    Month m2("Oct");

    cout << "Default month: ";
    m1.getMonthString(cout);
    cout << " (";
    m1.getMonthN(cout);
    cout << ")" << endl << endl;

    cout << "Month from string (Oct): ";
    m2.getMonthString(cout);
    cout << " (";
    m2.getMonthN(cout);
    cout << ")" << endl;

    cout << "Next month after ";
    m2.getMonthString(cout);
    cout << ": ";
    m2.nextMonth().getMonthString(cout);
    cout << endl << endl;

    cout << "Enter a month number: ";
    m1.setMonth(cin);
    cout << "You entered: ";
    m1.getMonthString(cout);
    cout << " (";
    m1.getMonthN(cout);
    cout << ")" << endl;

    cout << "Next month after ";
    m1.getMonthString(cout);
    cout << ": ";
    m1.nextMonth().getMonthString(cout);
    cout << endl;

    return 0;
}


void Month::setMonth(istream& f) {
    f >> month_no;
    if (month_no < 1 || month_no > 12) {
        cout << "Invalid month number! Month set to January." << endl;
        month_no = 1;
    }
}

void Month::getMonthN(ostream& f) {
    f << month_no;
}

void Month::getMonthString(ostream& f) {
    f << find_monthstr(month_no);
}

Month Month::nextMonth() {
    if (month_no == 12) return Month("Jan");
    return Month(find_monthstr(month_no + 1));
}

int Month::find_monthno(string month) {

    if (month.length() < 3) return 0;

    for (int i = 0; i < 3; i++) {
        month[i] = tolower(month[i]);
    }

    if (month.substr(0,3) == "jan") return 1;
    if (month.substr(0,3) == "feb") return 2;
    if (month.substr(0,3) == "mar") return 3;
    if (month.substr(0,3) == "apr") return 4;
    if (month.substr(0,3) == "may") return 5;
    if (month.substr(0,3) == "jun") return 6;
    if (month.substr(0,3) == "jul") return 7;
    if (month.substr(0,3) == "aug") return 8;
    if (month.substr(0,3) == "sep") return 9;
    if (month.substr(0,3) == "oct") return 10;
    if (month.substr(0,3) == "nov") return 11;
    if (month.substr(0,3) == "dec") return 12;

    return 0;
}

string Month::find_monthstr(int n) {
    if (n == 1) return "Jan";
    if (n == 2) return "Feb";
    if (n == 3) return "Mar";
    if (n == 4) return "Apr";
    if (n == 5) return "May";
    if (n == 6) return "Jun";
    if (n == 7) return "Jul";
    if (n == 8) return "Aug";
    if (n == 9) return "Sep";
    if (n == 10) return "Oct";
    if (n == 11) return "Nov";
    if (n == 12) return "Dec";
    return "Invalid";
}

Month::Month() {
    month_no = 1;
}

Month::Month(string month) {
    month_no = find_monthno(month);
    if (month_no == 0) {
        cout << "Invalid month name! Month set to January." << endl;
        month_no = 1;
    }
}




/* OUTPUT:

Default month: Jan (1)

Month from string (Oct): Oct (10)
Next month after Oct: Nov

Enter a month number: 12
You entered: Dec (12)
Next month after Dec: Jan

Process finished with exit code 0

*/