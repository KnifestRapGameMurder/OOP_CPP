#pragma once
#include<iostream>
#include<cstring>

///////////////////////////////////////////////////////////////////////
////////////////////////	CLASS	DECLARATION		///////////////////
///////////////////////////////////////////////////////////////////////

class String;
String operator+(const String& str1, const String& str2);

class String
{
	int size;
	char* str;	//Number of bites
public:
	//	GET METHODS
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//	SET METHODS
	void set_str(const char* str);
	//		CONSTRUCTORS
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//		OPERATORS
	String& operator=(const String& other);
	String& operator+=(const String& other);
	/*String& operator=(String&& source);*/
	const char& operator[](int i) const;
	char& operator[](int i);
	//		Methods:
	void print();
};

std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);
bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);
bool operator<(const String& left, const String& right);
bool operator>(const String& left, const String& right);

////////////////////////////////////////////////////////////////////////////////