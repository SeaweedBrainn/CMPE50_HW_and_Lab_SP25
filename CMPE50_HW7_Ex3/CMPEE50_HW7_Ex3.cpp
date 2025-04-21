//============================================================================
// Name : CMPE50_HW7_Ex3.cpp
// Author : Hemang Mehra
// Description : The output of HW7 exercise 3.
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class StringArray {
public:
    StringArray();
    StringArray(const StringArray& other);
    ~StringArray();
    bool Add(string& newEntry);
    bool Delete(string& deleteEntry);
    string get(int pos);
    int getSize();
private:
    string* DynamicArray;
    int size;
};

int main() {
    StringArray arr;

    string str1 = "Hello";
    string str2 = "World";
    string str3 = "Test";
    arr.Add(str1);
    arr.Add(str2);
    arr.Add(str3);

    cout << "Size after adding elements: " << arr.getSize() << endl;

    for (int i = 0; i < arr.getSize(); i++) {
        cout << "Element at position " << i << ": " << arr.get(i) << endl;
    }
    cout << endl;

    cout << "Deleting element: " << str2 << endl;
    arr.Delete(str2);
    cout << "Size after deleting element: " << arr.getSize() << endl;

    for (int i = 0; i < arr.getSize(); i++) {
        cout << "Element at position " << i << ": " << arr.get(i) << endl;
    }
    cout << endl;

    string str4 = "NewString";
    cout << "Adding new element: " << str4 << endl;
    arr.Add(str4);
    cout << "Size after adding another element: " << arr.getSize() << endl;
    for (int i = 0; i < arr.getSize(); i++) {
        cout << "Element at position " << i << ": " << arr.get(i) << endl;
    }

    return 0;
}

StringArray::StringArray() {
    size = 0;
    DynamicArray = nullptr;
}

StringArray::~StringArray() {
    delete [] DynamicArray;
}

StringArray::StringArray(const StringArray& other) {
    size = other.size;
    DynamicArray = new string[size];
    for (int i = 0; i < size; i++) {
        DynamicArray[i] = other.DynamicArray[i];
    }
}

bool StringArray::Add(string& newEntry) {
    string* NewArray = new string[size + 1];
    for (int i = 0; i < size; i++) {
        NewArray[i] = DynamicArray[i];
    }
    NewArray[size] = newEntry;

    delete [] DynamicArray;
    size = size + 1;
    DynamicArray = new string[size];

    for (int i = 0; i < size; i++) {
        DynamicArray[i] = NewArray[i];
    }
    delete [] NewArray;
    return true;
}

bool StringArray::Delete(string &deleteEntry) {
    int pos;
    for (pos = 0; pos < size; pos++) {
        if (DynamicArray[pos] == deleteEntry) {
            break;
        }
    }

    if (pos == size) {
        return false;
    }

    string* NewArray = new string[size - 1];
    for (int i = 0; i < pos; i++) {
        NewArray[i] = DynamicArray[i];
    }

    for (int i = pos + 1; i < size; i++) {
        NewArray[i - 1] = DynamicArray[i];
    }

    delete [] DynamicArray;
    size = size - 1;
    DynamicArray = new string[size];

    for (int i = 0; i < size; i++) {
        DynamicArray[i] = NewArray[i];
    }
    delete [] NewArray;
    return true;
}

string StringArray::get(int pos) {
    if (pos < 0 || pos >= size) {
        return "NULL"; //I am assuming that the question meant for us to literally return "NULL" as a string because returning NULL was crashing the program
    }
    return DynamicArray[pos];
}

int StringArray::getSize() {
    return size;
}

/* OUTPUT:
Size after adding elements: 3
Element at position 0: Hello
Element at position 1: World
Element at position 2: Test

Deleting element: World
Size after deleting element: 2
Element at position 0: Hello
Element at position 1: Test

Adding new element: NewString
Size after adding another element: 3
Element at position 0: Hello
Element at position 1: Test
Element at position 2: NewString

Process finished with exit code 0
*/