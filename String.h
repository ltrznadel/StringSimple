#pragma once
#include <iostream>
#include <cctype>

// TODO Add comparison operators

class String
{
	static int howMany;	//how many Strings present in the program

	char* contentString;
	size_t stringSize;

public:
	//constructors
	String();
	String(const char* input);
	String(const String& st);
	~String();

	//funcs
	size_t length() { return stringSize; }
	void stringlow();
	void stringup();
	int stringOccur(const char* ch);

	//operators
	String& operator=(const String& st);
	String& operator=(const char* ch);
	//operator + concatenates Strings
	String operator+(const String& st) const;
	String operator+(const char* ch) const;
	//access to String
	char & operator[](int i);
	const char & operator[](int i) const;		//for use with const String objects
	//String comparisons
	bool operator==(String& st) const;
	//bool operator==(const char* ch) const; <- to finish later

	//friend foos
	friend std::ostream & operator<<(std::ostream & os, const String& st);
	friend String& operator+(const char* ch, const String& st);

};

