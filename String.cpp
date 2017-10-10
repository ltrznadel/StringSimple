#include "String.h"
#include <cstring>

int String::howMany = 0;

String::String()
{
	contentString = new char[4]{ "C++" };
	stringSize = 3;
	std::cout << "String created, default constructor\n";
	howMany++;
}

String::String(const char* input)
{
	stringSize = strlen(input);
	contentString = new char[stringSize + 1];
	strcpy(contentString, input);
	std::cout << "String created\n";
	howMany++;
}

String::String(const String & st)
{
	contentString = new char[st.stringSize + 1];
	strcpy(this->contentString, st.contentString);
	this->stringSize = st.stringSize;

	howMany++;
}

String::~String()
{
	delete[] contentString;
	howMany--;
}

void String::stringlow()
{
	for (size_t i = 0; i < stringSize + 1; i++) {
		contentString[i] = tolower(contentString[i]);
	}
}

void String::stringup()
{
	for (size_t i = 0; i < stringSize + 1; i++) {
		contentString[i] = toupper(contentString[i]);
	}
}

int String::stringOccur(const char * ch)
{
	int occur = 0;		//occurences in string
	int internIt;		//loop internal iterator
	size_t inputLen = strlen(ch);
	
	if(inputLen > stringSize)
	return 0;

	//counting the occurences
	for (int i = 0; i < stringSize - inputLen + 1; i++) {
		for (internIt = 0; internIt < inputLen; internIt++) {
			if (ch[internIt] != contentString[internIt + i])
				break;
			if (internIt == inputLen - 1)
				occur++;
		}
	}
	//done

	return occur;
}

String& String::operator=(const String& st)
{
	delete[] contentString;
	size_t tempSize;
	tempSize = st.stringSize;

	contentString = new char[tempSize + 1];
	strcpy(this->contentString, st.contentString);
	this->stringSize = tempSize;

	return *this;
}

String  String::operator+(const String & st)
{
	char* tempString = new char[this->stringSize + st.stringSize + 1];
	strcpy(tempString, this->contentString);
	strcat(tempString, st.contentString);
	
	String returnTemp(tempString);
	delete[] tempString;

	return returnTemp;
}

char & String::operator[](int i)
{
	if (i > stringSize)
	{
		std::cout << "Access Error: out of memory bounds\n";
		return contentString[0];
	}
	else
		return contentString[i];
}

bool String::operator==(String & st) const
{
	int temp = 0;		//loop iterator
	if (st.stringSize == this->stringSize) {
		for (temp = 0; temp < stringSize; temp++)
			if (this->contentString[temp] != st[temp])
				return false;
	}

	return true;
}

const char & String::operator[](int i) const
{
	if (i > stringSize)
	{
		std::cout << "Access Error: out of memory bounds\n";
		return contentString[0];
	}
	else
		return contentString[i];
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
	os << st.contentString;
	return os;
}

