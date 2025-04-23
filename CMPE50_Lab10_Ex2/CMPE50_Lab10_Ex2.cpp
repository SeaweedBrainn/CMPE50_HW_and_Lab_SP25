//============================================================================
// Name : CMPE50_Lab10_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of Lab10 exercise 1.
//============================================================================

#include <iostream>
#include "figure.h"
#include "circle.h"
#include "triangle.h"

using namespace std;

void myDraw(figure *fig)
{
	fig->draw();
	cout << "\n myDraw: Derived class object calling center(). \n";
	fig->center();	
}

int main(){
	figure *fig;
	triangle *tri = new triangle;

	fig = tri;
	fig->draw();
	cout << "\n Derived class Triangle object calling center(). \n";
	fig->center();

	myDraw(tri);

	circle *cir = new circle;
	fig = cir;
	fig->draw();
	cout << "\n Derived class Circle object calling center(). \n";
	fig->center();

	myDraw(cir);

	return 0;
}

/* Case 1: Non-virtualized
Drawing a figure.

Derived class Triangle object calling center().
********
Centering a figure:
Erasing a figure.
Drawing a figure.
********
Drawing a figure.

myDraw: Derived class object calling center().
********
Centering a figure:
Erasing a figure.
Drawing a figure.
********
Drawing a figure.

Derived class Circle object calling center().
********
Centering a figure:
Erasing a figure.
Drawing a figure.
********
Drawing a figure.

myDraw: Derived class object calling center().
********
Centering a figure:
Erasing a figure.
Drawing a figure.
********

Process finished with exit code 0
*/

/* Case 2: Virtualized
Drawing a triangle.

 Derived class Triangle object calling center().
********
Centering a figure:
Erasing a triangle.
Drawing a triangle.
********
Drawing a triangle.

 myDraw: Derived class object calling center().
********
Centering a figure:
Erasing a triangle.
Drawing a triangle.
********
Drawing a circle.

 Derived class Circle object calling center().
********
Centering a figure:
Erasing a circle.
Drawing a circle.
********
Drawing a circle.

 myDraw: Derived class object calling center().
********
Centering a figure:
Erasing a circle.
Drawing a circle.
********

Process finished with exit code 0
*/

/* The derived class functions are called when virtual functions are used.
 * This is because the base class pointer points to the derived class object and the child class functions are called.
 * In non-virtualized functions only the base class functions were called.
 */
