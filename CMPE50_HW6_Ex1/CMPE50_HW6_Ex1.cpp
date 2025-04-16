//============================================================================
// Name : CMPE50_HW6_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of HW6 exercise 1
//============================================================================

#include <iostream>
using namespace std;

class DayOfYear
{
public:
    friend bool equal(DayOfYear date1, DayOfYear date2);
    //Precondition: date1 and date2 have values.
    //Returns true if date1 and date2 represent the same date;
    //otherwise, returns false.

    friend bool isAfter(DayOfYear date1, DayOfYear date2);
    friend bool isBefore(DayOfYear date1, DayOfYear date2);

    friend DayOfYear add(DayOfYear date1, DayOfYear date2);

    DayOfYear(int the_month, int the_day);
    //Precondition: the_month and the_day form a
    //possible date. Initializes the date according
    //to the arguments.

    DayOfYear();
    //Initializes the date to January first.

    void input( );

    void output( );

    int get_month( );
    //Returns the month, 1 for January, 2 for February, etc.

    int get_day( );
    //Returns the day of the month.
private:
    void check_date( );
    int month;
    int day;
};

int main() {

    DayOfYear today(9,1), bach_birthday(8, 30), yesterday(8,29);

    DayOfYear result = add(today, yesterday);
    cout << "The result of adding today (9,1) and yesterday (8,29) is: ";
    result.output();


    if (isAfter(today, bach_birthday))
        cout << "Today (9,1) is after Bach's birthday (8,30).\n";
    else
        cout << "Today is not after Bach's birthday.\n";


    if (isBefore(yesterday, bach_birthday))
        cout << "Yesterday (8,29) is before Bach's birthday (8,30).\n";
    else
        cout << "Yesterday is not before Bach's birthday.\n";

    return 0;
}


bool equal(DayOfYear date1, DayOfYear date2)
{
    return ( date1.month == date2.month &&
                           date1.day == date2.day );
}

DayOfYear::DayOfYear(int the_month, int the_day)
                  : month(the_month), day(the_day)
{
    check_date();
}
DayOfYear::DayOfYear() : month(1), day(1)
{

}

int DayOfYear::get_month( )
{
    return month;
}

int DayOfYear::get_day( )
{
    return day;
}

//Uses iostream:
void DayOfYear::input( )
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    check_date();
}

//Uses iostream:
void DayOfYear::output( )
{
    cout << "month = " << month
         << ", day = " << day << endl;
}

void DayOfYear::check_date()
{
    if (month < 1 || month > 12)
    {
        day = 1;
        month = 1;
    }
    if (day < 1 || day > 30)
    {
        month = 1;
        day = 1;
    }
}

bool isAfter(DayOfYear date1, DayOfYear date2) {
    if (date1.month == date2.month)
        if (date1.day == date2.day + 1) return true;
    if (date1.month == date2.month + 1 || date1.month == 1 && date2.month == 12)
        if (date1.day == 1 && date2.day == 30) return true;
    return false;
}

bool isBefore(DayOfYear date1, DayOfYear date2) {
    if (date1.month == date2.month)
        if (date1.day == date2.day - 1) return true;
    if (date1.month == date2.month - 1 || date1.month == 12 && date2.month == 1)
        if (date1.day == 30 && date2.day == 1) return true;
    return false;
}

//I didn't get what was meant by "adding dates", so I assumed it meant
//adding what date I'd get if I added the number of days of each date.
DayOfYear add(DayOfYear date1, DayOfYear date2) {
    DayOfYear result;

    int days1 = date1.day + (date1.month-1)*30;
    int days2 = date2.day + (date2.month-1)*30;

    int daysFinal = days1 + days2;
    int monthsFinal = 1;

    if (daysFinal > 360) daysFinal %= 360;

    if (daysFinal < 1) daysFinal = 1;

    while (daysFinal > 30) {
        monthsFinal++;
        daysFinal -= 30;
    }

    result.day = daysFinal;
    result.month = monthsFinal;

    return result;
}

/* OUTPUT:
The result of adding today (9,1) and yesterday (8,29) is: month = 4, day = 30
Today (9,1) is after Bach's birthday (8,30).
Yesterday (8,29) is before Bach's birthday (8,30).

Process finished with exit code 0
*/