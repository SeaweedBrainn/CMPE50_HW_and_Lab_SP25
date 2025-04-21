//============================================================================
// Name        : URLEncode.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//DISPLAY 11.11 Program Using the StringVar Class
//This is the definition for the class StringVar
//whose values are strings. An object is declared as follows.
//Note that you use (max_size), not [max_size]
//     StringVar the_object(max_size);
//where max_size is the longest string length allowed.

#include <iostream>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class StringVar
{
public:
	StringVar(int size);
	//Initializes the object so it can accept string values up to size
	//in length. Sets the value of the object equal to the empty string.

	StringVar( );
	//Initializes the object so it can accept string values of length 100
	//or less. Sets the value of the object equal to the empty string.

	StringVar(const char a[]);
	//Precondition: The array a contains characters terminated with '\0'.
	//Initializes the object so its value is the string stored in a and
	//so that it can later be set to string values up to strlen(a) in length

	StringVar(const StringVar& string_object);
	//Copy constructor.

	~StringVar( );
	//Returns all the dynamic memory used by the object to the freestore.

	int length( ) const;
	//Returns the length of the current string value.

	void input_line(istream& ins);
	//Precondition: If ins is a file input stream, then ins has been
	//connected to a file.
	//Action: The next text in the input stream ins, up to '\n', is copied
	//to the calling object. If there is not sufficient room, then
	//only as much as will fit is copied.
	friend ostream& operator <<(ostream& outs, const StringVar& the_string);

	//Overloads the << operator so it can be used to output values
	//of type StringVar
	//Precondition: If outs is a file output stream, then outs
	//has already been connected to a file.

	StringVar operator= (const StringVar &str);

protected:
	char *value; //pointer to dynamic array that holds the string value.
	int max_length; //declared max length of any string value.
};


StringVar::StringVar( ) : max_length(100)
{
	this->value = new char[max_length + 1];//+1 is for '\0'.
	this->value[0] = '\0';
}

StringVar::StringVar(int size) : max_length(size)
{
	this->value = new char[max_length + 1];//+1 is for '\0'.
	this->value[0] = '\0';
}

StringVar::StringVar(const char a[]) : max_length(strnlen(a,100))
{
	this->value = new char[max_length + 1];//+1 is for '\0'.
	strncpy(this->value, a, 100);
}

StringVar::StringVar(const StringVar& string_object)
: max_length(string_object.length( ))
{
	this->value = new char[max_length + 1];//+1 is for '\0'.
	strncpy(this->value, string_object.value, 100);
}

StringVar::~StringVar( )
{
	delete [] this->value;
}

int StringVar::length( ) const
{
	return strnlen(this->value, this->max_length);
}

void StringVar::input_line(istream& ins)
{
	ins.getline(this->value, max_length + 1);
}

StringVar StringVar::operator=(const StringVar &str)
{
	if (this == &str)
		return *this;
	delete [] this->value;
	this->max_length = str.length();
	this->value = new char[this->max_length + 1];
	strncpy(this->value, str.value, 100);
	return *this;
}

ostream& operator <<(ostream& outs, const StringVar& the_string)
{
	outs << the_string.value;
	return outs;
}

/*
 * Defining the URLEncoder to demonstrate how copy constructor and operator= are
 * implemented.
 */

class URLEncoder : public StringVar
{
public:
	URLEncoder();
	URLEncoder(int size);
	URLEncoder(char str[]);
	URLEncoder(const URLEncoder &obj);
	~URLEncoder();
	URLEncoder & operator= (const URLEncoder &other);
	bool Encode();
	char *get_string(); // get the original string (from the StringVar)
	char *get_url(); // accessor
	int get_length(); // accessor

	friend ostream& operator<<(ostream &ost, const URLEncoder & enc);
private:
	char *urlstring;
	int urlMaxLength;

};

URLEncoder::URLEncoder() : StringVar()
{
	urlMaxLength = max_length * 2; // always double the buffer for the encoder
	urlstring = new char[urlMaxLength+1];
	urlstring[0] = '\0';
}

URLEncoder::URLEncoder(int size) : StringVar(size)
{
	urlMaxLength = max_length * 2; // always double the buffer for the encoder
	urlstring = new char[urlMaxLength+1];
	urlstring[0] = '\0';
}

// Copy constructor
URLEncoder::URLEncoder(const URLEncoder &obj) : StringVar(obj)
{
	urlMaxLength = obj.urlMaxLength;
	urlstring = new char[obj.urlMaxLength + 1];
	strncpy(this->urlstring, obj.urlstring, urlMaxLength);
}

URLEncoder & URLEncoder::operator=(const URLEncoder &other)
{
	if (&other == this)
		return *this;
	StringVar::operator=(other);

	delete [] this->urlstring;
	this->urlMaxLength = other.urlMaxLength;
	this->urlstring = new char[this->urlMaxLength + 1];
	strncpy(this->urlstring, other.urlstring, this->urlMaxLength);

	return *this;
}

char *URLEncoder::get_string()
{
	return value;
}

URLEncoder::~URLEncoder()
{
	delete [] urlstring;
}

string url_encode(const string &value);

bool URLEncoder::Encode()
{
	// covert the c-string to a string object since the url_encode()
	// function needs a string object
	string in(this->get_string());
	string url = url_encode(in);

	if (url.length() >= this->urlMaxLength)
	{
		// Too long. Do not have enough buffer.
		return false;
	}
	// convert the encoded URL string object to c-string
	int i;
	for (i = 0; i < url.length(); i++)
	{
		this->urlstring[i] = url[i];
	}
	this->urlstring[i] = '\0';

	return true;
}

ostream& operator<<(ostream &ost, const URLEncoder & enc)
{
	for (int i = 0; i < enc.max_length; i++)
	{
		if (enc.value[i] == '\0')
			break;
		ost << enc.value[i];
	}
	ost << endl;
	for (int i=0; i < enc.urlMaxLength; i++)
	{
		if (enc.urlstring[i] == '\0')
			break;
		ost << enc.urlstring[i];
	}
	ost << endl;

	return ost;
}

using namespace std;

/*
 * URL encoding rule is to keep all alphanumeric letters, '-', '_', '.', and '~'
 * intact and convert any other letters using the hex values with a leading '%'
 * (called percent-encoded).
 * For example, the following string
 * 		Hello + World?id=10&name="George"
 * is encoded as
 * 		Hello%20%2B%20World%3Fid%3D10%26name%3D%22George%22
 * where a space is encoded as "%20", a plus sign '+' is encoded as "%2B", etc.
 * Please refer to an ASCII for the hex value of any letter.
 */
string url_encode(const string &value) {
    ostringstream escaped;
    escaped.fill('0');
    escaped << hex;

    for (auto &c : value)
    {
    	/* Without the auto type one would have to code the following:
    	 *
    	for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        string::value_type c = (*i);
         *
         */

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << uppercase;
        escaped << '%' << setw(2) << int((unsigned char) c);
        escaped << nouppercase;
    }

    return escaped.str();
}

int main( )
{

	URLEncoder obj(1000);
	// input some string to be converted to URL
	// For example, the string
	//	Hello + World?id=10&name="George"
	// should be URL-encoded as
	//	Hello%20%2B%20World%3Fid%3D10%26name%3D%22George%22
	obj.input_line(cin);
	obj.Encode();
	cout << "Encoding ..." << endl;
	cout << obj << endl;

	// Demonstrate the copy constructor
	URLEncoder obj2(obj);
	cout << obj2 << endl;

	// Demonstrate the operator=
	URLEncoder obj3;
	obj3 = obj;
	cout << obj3;

	return 0;
}



