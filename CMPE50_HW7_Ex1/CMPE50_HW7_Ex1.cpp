//============================================================================
// Name : CMPE50_HW7_Ex1.cpp
// Author : Hemang Mehra
// Description : The output of HW7 exercise 1
//============================================================================

#include <iostream>
#include <string>
using namespace std;
/* Class SuperString for HW7 */

class sstring: public string
{
public:
    sstring() : string() { };
    sstring(const string &str) : string(str) { }
    sstring(const sstring &sstr) : string(sstr) { }
    sstring operator= (const sstring &sstr);
    sstring operator= (const char *cstr);
    friend sstring operator* (const sstring &sstr, int multiple);
    friend sstring operator- (const sstring &sstr1, const sstring &sstr2);
    friend sstring operator/ (const sstring &sstr, int divider);
    friend sstring operator! (const sstring &sstr);
    /* prefix increment */
    friend sstring operator++ (sstring &sstr);
    /* postfix increment */
    friend sstring operator++ (sstring &sstr, int dummy);
    /* prefix decrement */
    friend sstring operator-- (sstring &sstr);
    /* postfix decrement */
    friend sstring operator-- (sstring &sstr, int dummy);
};

int main() {
    sstring s1("Hello");
    cout << "s1 (constructed): " << s1 << "\n";

    sstring s2;
    s2 = s1;
    cout << "s2 (assigned s1): " << s2 << "\n";

    s2 = "World";
    cout << "s2 (assigned \"World\"): " << s2 << "\n\n";

    sstring s3 = s1 * 3;
    cout << "s3 = s1 * 3: " << s3 << "\n\n";

    sstring s4 = s3 - sstring("lo");
    cout << "s4 = s3 - \"lo\": " << s4 << "\n\n";

    sstring s5 = s3 / 2;
    cout << "s5 = s3 / 2: " << s5 << "\n\n";

    sstring s6 = !s1;
    cout << "s6 = !s1 (reverse): " << s6 << "\n\n";

    s1 = "Hello";
    cout << "Reset s1 = \"Hello\"\n";
    cout << "++s1: " << ++s1 << "\n\n";

    s1 = "Hello";
    cout << "Reset s1 = \"Hello\"\n";
    cout << "s1++: " << s1++
         << "   (now s1 = " << s1 << ")\n\n";

    s1 = "Hello";
    cout << "Reset s1 = \"Hello\"\n";
    cout << "--s1: " << --s1 << "\n\n";

    s1 = "Hello";
    cout << "Reset s1 = \"Hello\"\n";
    cout << "s1--: " << s1--
         << "   (now s1 = " << s1 << ")\n\n";

    return 0;
}

sstring sstring::operator= (const sstring &sstr)
{
    // calling base class opertor=
    string::operator=(sstr);
    return *this;
}
sstring sstring::operator= (const char *cstr)
{
    string::operator=(cstr);
    return *this;
}

sstring operator* (const sstring &sstr, int multiple)
{
    sstring temp = sstr;
    for (int i = 1; i < multiple; i++)
    {
        temp.append(sstr.c_str());
    }
    return temp;
}

sstring operator- (const sstring &sstr1, const sstring &sstr2)
{
    sstring temp = sstr1;
    int pos = temp.find(sstr2);
    while (pos != -1) {
        temp.erase(pos, sstr2.length());
        pos = temp.find(sstr2, pos);
    }
    return temp;
}

sstring operator/ (const sstring &sstr, int divider)
{
    sstring temp = sstr;
    int divided_length = sstr.length()/divider;
    temp.erase(divided_length);
    return temp;
}

sstring operator! (const sstring &sstr)
{
    sstring temp;
    char *reversed = new char[sstr.length() + 1];
    for (int i = sstr.length()-1; i >= 0; i--) {
        reversed[sstr.length()-i-1] = sstr[i];
    }
    reversed[sstr.length()] = '\0';
    temp = reversed;
    delete [] reversed;
    return temp;
}

sstring operator++ (sstring &sstr) {
    char* changed = new char[sstr.length() + 1];
    for (int i = 1; i < sstr.length(); i++) {
        changed[i] = sstr[i-1];
    }
    changed[0] = sstr[sstr.length() - 1];
    changed[sstr.length()] = '\0';
    sstr = changed;

    delete [] changed;

    return sstr;
}

sstring operator++ (sstring &sstr, int dummy) {
    sstring temp = sstr;
    char* changed = new char[sstr.length() + 1];
    for (int i = 1; i < sstr.length(); i++) {
        changed[i] = sstr[i-1];
    }
    changed[0] = sstr[sstr.length() - 1];
    changed[sstr.length()] = '\0';
    sstr = changed;

    delete [] changed;

    return temp;
}

sstring operator-- (sstring &sstr) {
    char* changed = new char[sstr.length() + 1];
    for (int i = 0; i < sstr.length()-1; i++) {
        changed[i] = sstr[i+1];
    }
    changed[sstr.length()-1] = sstr[0];
    changed[sstr.length()] = '\0';
    sstr = changed;

    delete [] changed;

    return sstr;
}

sstring operator-- (sstring &sstr, int dummy) {
    sstring temp = sstr;
    char* changed = new char[sstr.length() + 1];
    for (int i = 0; i < sstr.length()-1; i++) {
        changed[i] = sstr[i+1];
    }
    changed[sstr.length()-1] = sstr[0];
    changed[sstr.length()] = '\0';
    sstr = changed;

    delete [] changed;

    return temp;
}

/* Output:
* s1 (constructed): Hello
s2 (assigned s1): Hello
s2 (assigned "World"): World

s3 = s1 * 3: HelloHelloHello

s4 = s3 - "lo": HelHelHel

s5 = s3 / 2: HelloHe

s6 = !s1 (reverse): olleH

Reset s1 = "Hello"
++s1: oHell

Reset s1 = "Hello"
s1++: Hello   (now s1 = oHell)

Reset s1 = "Hello"
--s1: elloH

Reset s1 = "Hello"
s1--: Hello   (now s1 = elloH)


Process finished with exit code 0
*/