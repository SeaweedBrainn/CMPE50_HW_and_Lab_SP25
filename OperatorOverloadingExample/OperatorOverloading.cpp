/*
 * OperatorOverloading.cpp
 *
 *  Created on: Oct 1, 2015
 *      Author: chaolitarng
 *
 *  Description: The operator overloading can be done either as
 *  member functions (e.g., in class MyInt) or as friend functions
 *  (e.g., in class MyInt2).
 */

#include <iostream>
// using namespace std;
using std::cin;
using std::cout;
using std::ostream;
using std::endl;


// This sample class MyInt demonstrates the operator overloading using member
// functions.
class MyInt {
public:
	MyInt() { value = 0; };

	MyInt(int val) : value(val) { };

	// Binary operator = (assign)
	// This can only be implemented as a member function.
	MyInt operator=(const MyInt other)
		{ this->value = other.value; return *this; };

	// Binary operator + (add)
	MyInt operator+(const MyInt other) const
		{ return MyInt(this->value + other.value); };

	// Binary operator == (equal)
	bool operator==(const MyInt other) const
		{ return (this->value == other.value); };

	// Unary operator - (negate)
	MyInt operator-() const
		{ return MyInt(-this->value); };

	// Binary operator - (subtract)
	MyInt operator-(MyInt other) const
		{ return MyInt(this->value - other.value); };

	// prefix ++ operator
	MyInt operator++() { ++this->value; return *this; }

	// postfix ++ operator, need a dummy argument of type int
	MyInt operator++(int) { MyInt temp = *this; ++this->value; return temp; }
	friend ostream& operator << (ostream & ost, const MyInt);

	/*
	 * int v1 = 5, v2;
	 *
	 * v2 = v1++;
	 *
	 * cout << v2; (1) 5 or (2) 6
	 * cout << v1; 6
	 */
private:
	int value;
};

// This sample class MyInt2 demonstrates the operator overloading using friend
// functions.
class MyInt2 {
public:
	MyInt2() { value = 0; };
	MyInt2(int val) : value(val) { };

	// Binary operator = (assign)
	// operator= cannot be a friend function, must be overloaded as a member function
	MyInt2 operator=(const MyInt2 other)
		{ this->value = other.value; return *this;};

	// Binary operator + (add)
	friend MyInt2 operator+(const MyInt2 lhs, const MyInt2 rhs)
		{ return MyInt2(lhs.value + rhs.value); };

	// Binary operator == (equal)
	friend bool operator==(const MyInt2 lhs, const MyInt2 rhs)
		{return (lhs.value == rhs.value); };

	// Unary operator - (negate)
	friend MyInt2 operator-(const MyInt2 other)
		{ return MyInt2(-other.value); };

	// Binary operator - (subtract)
	friend MyInt2 operator-(const MyInt2 lhs, const MyInt2 rhs)
		{ return MyInt2(lhs.value - rhs.value); };

	// prefix ++ operator
	friend MyInt2 operator++(MyInt2 &obj) { ++obj.value; return obj; }

	// MyInt2 i(10);
	// ++i;

	// postfix ++ operator, need a dummy argument of type int
	friend MyInt2 operator++(MyInt2 &obj, int) {
		MyInt2 temp = obj;
		obj.value++;
		return temp; }

	// MyInt2 i(10);
	// i++;

	friend ostream& operator << (ostream & ost, const MyInt2);

private:
	int value;
};

// Overloaded insertion operator for MyInt
ostream& operator<<(ostream& ost, const MyInt obj)
{
	ost << obj.value;
	return ost;
}

// Overloaded insertion operator for MyInt2
ostream& operator<<(ostream& ost, const MyInt2 obj)
{
	ost << obj.value;
	return ost;
}


#define TypeV	MyInt

int main()
{
	// Replace MyInt with MyInt2 and get the identical results.
	MyInt2 ival(100), ival2, ival3;

	// operator= invoked below
	ival2 = ival;

	// operator<< invoked below
	cout << ival << endl;
	cout << ival2 << endl;

	// operator+ and operator= invoked below
	ival3 = ival + ival2;
	cout << ival3 << endl;

	// operator== invoked below
	if (ival == ival2)
	{
		cout << "Yes ival is equal to ival2!" << endl;
	}

	// operator+ and constructor(int) invoked below
	ival2 = ival + 1000;

	cout << "ival2 is " << ival2 << endl;

	// binary operator- invoked below
	ival2 = ival2 - 500;
	cout << "ival2 is " << ival2 << endl;

	// unary operator- invoked below
	cout << "-ival2 is " << -ival2 << endl;

	ival2++;
	cout << "ival2++ = " << ival2 << endl;
	++ival2;
	cout << "++ival2 = " << ival2 << endl;

	return 0;
}




