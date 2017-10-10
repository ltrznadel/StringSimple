#pragma once
#include <iostream>
#include <cctype>

// TODO Add comparison operators

class String
{
	static int howMany;

	char* contentString;
	size_t stringSize;

public:
	String();
	String(const char* input);
	String(const String& st);
	~String();

	size_t length() { return stringSize; }
	void stringlow();
	void stringup();
	int stringOccur(const char* ch);

	String& operator=(const String& st);
	String operator+(const String& st);
	char & operator[](int i);
	bool operator==(String& st) const;
	const char & operator[](int i) const;		//for use with const String objects
	//friend foos
	friend std::ostream & operator<<(std::ostream & os, const String& st);

};

