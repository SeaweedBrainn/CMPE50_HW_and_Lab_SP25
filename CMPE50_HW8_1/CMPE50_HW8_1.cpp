//============================================================================
// Name : CMPE50_HW8_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of HW8 exercise 1.
//============================================================================

#include <iostream>
using namespace std;
#include <cstddef>
#include <cstdlib>

class StringVar
{
public:
    StringVar(int size);
    StringVar( );
    StringVar(const char a[]);
    StringVar(const StringVar& string_object);
    ~StringVar( );
    int length( ) const;
    void input_line(istream& ins);
    StringVar copy_piece(int pos, int npos);
    char one_char(int pos);
    void set_char(int pos, char ch);
    StringVar& operator=(const StringVar &obj);
    friend istream& operator >>(istream& ins, StringVar& the_string);
    friend ostream& operator <<(ostream& outs, const StringVar& the_string);
    friend bool operator==(const StringVar& sv1, const StringVar& sv2);
    friend StringVar operator+(const StringVar& sv1, const StringVar& sv2);

private:
    char *value;
    int max_length;
};

int main() {
    StringVar original("I em the infamous ");

    cout << "Original string: " << original << endl;

    StringVar piece = original.copy_piece(5, 6);
    cout << "copy_piece(5, 6): " << piece << endl;

    cout << "one_char(2): " << original.one_char(2) << endl;

    original.set_char(2, 'a');
    cout << "After set_char(2, 'a'): " << original << endl;

    StringVar assigned;
    assigned = original;
    cout << "After assignment: " << assigned << endl;

    StringVar inputWord(50);
    cout << "Enter a word (for operator >>): ";
    cin >> inputWord;
    cout << "You entered (operator <<): " << inputWord << endl;

    if (original == assigned) {
        cout << "Equality test passed (operator ==)" << endl;
    } else {
        cout << "Equality test failed (operator ==)" << endl;
    }

    StringVar combined = original + inputWord;
    cout << "Concatenation result (operator +): " << combined << endl;

    return 0;
}



//Uses cstddef and cstdlib:
StringVar::StringVar(int size) : max_length(size)
{
    value = new char[max_length + 1];//+1 is for '\0'.
    value[0] = '\0';
}

//Uses cstddef and cstdlib:
StringVar::StringVar( ) : max_length(100)
{
    value = new char[max_length + 1];//+1 is for '\0'.
    value[0] = '\0';
}

//Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const char a[]) : max_length(strlen(a))
{
    value = new char[max_length + 1];//+1 is for '\0'.
    strcpy(value, a);
}
//Uses cstring, cstddef, and cstdlib:
StringVar::StringVar(const StringVar& string_object)
                        : max_length(string_object.length( ))
{
    value = new char[max_length + 1];//+1 is for '\0'.
    strcpy(value, string_object.value);
}

StringVar::~StringVar( )
{
    delete [] value;
}

//Uses cstring:
int StringVar::length( ) const
{
    return strlen(value);
}

//Uses iostream:
void StringVar::input_line(istream& ins)
{
    ins.getline(value, max_length + 1);
}

StringVar StringVar::copy_piece(int pos, int npos)
{
    StringVar temp(npos);
    for (int i = 0; i < npos && (pos + i) < max_length; i++) {
        temp.value[i] = value[pos + i];
    }
    temp.value[npos] = '\0';
    return temp;
}

char StringVar::one_char(int pos)
{
    if (pos < 0 || pos >= max_length) {
        cout << "Error: Index out of bounds." << endl;
        exit(1);
    }
    return value[pos];
}

void StringVar::set_char(int pos, char ch)
{
    if (pos < 0 || pos >= max_length) {
        cout << "Error: Index out of bounds." << endl;
        exit(1);
    }
    value[pos] = ch;
}

StringVar&StringVar::operator=(const StringVar &obj)
{
    if (this == &obj) return *this;
    delete[] value;
    value = new char[obj.max_length + 1];
    max_length = obj.max_length;
    strcpy(value, obj.value);
    return *this;

}

//Uses iostream:
ostream& operator <<(ostream& outs, const StringVar& the_string)
{
    outs << the_string.value;
    return outs;
}

istream& operator >>(istream& ins, StringVar& the_string)
{
    char temp[100];
    ins >> temp;
    delete[] the_string.value;
    if (strlen(temp) > the_string.max_length) the_string.max_length = strlen(temp);
    the_string.value = new char[the_string.max_length + 1];
    strcpy(the_string.value, temp);
    return ins;
}

bool operator ==(const StringVar& sv1, const StringVar& sv2)
{
    if (strlen(sv1.value) != strlen(sv2.value)) return false;

    for (int i = 0; i < strlen(sv1.value); i++)
        if (sv1.value[i] != sv2.value[i]) return false;

    return true;
}

StringVar operator +(const StringVar& sv1, const StringVar& sv2)
{
    StringVar temp(sv1.max_length + sv2.max_length);
    strcpy(temp.value, sv1.value);
    strcat(temp.value, sv2.value);
    return temp;
}

/* OUTPUT:
Original string: I em the infamous
copy_piece(5, 6): the in
one_char(2): e
After set_char(2, 'a'): I am the infamous
After assignment: I am the infamous
Enter a word (for operator >>): ODYSSEUS!!
You entered (operator <<): ODYSSEUS!!
Equality test passed (operator ==)
Concatenation result (operator +): I am the infamous ODYSSEUS!!

Process finished with exit code 0
*/