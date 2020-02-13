#include"String.h"

///////////////////////////////////////////////////////////////////////
////////////////////////	CLASS	DEFINITION		///////////////////
///////////////////////////////////////////////////////////////////////

		//	GET METHODS
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//	SET METHODS
void String::set_str(const char* str)
{
	delete[] this->str;
	this->size = strlen(str) + 1;
	this->str = new char[size] {};
	strcpy_s(this->str, this->size, str);
}

//	CONSTRUCTORS
String::String(int size) :size(size), str(new char[size] {})
{
	std::cout << "DefaultConstructor:\t" << this << std::endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	for (int i = 0; i < size; i++)	this->str[i] = str[i];
	std::cout << "Constructor:\t" << this << std::endl;
}
String::String(const String& other) : String(other.str)
{
	std::cout << "CopyConstructor:\t" << this << std::endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{
	other.str = nullptr;
	std::cout << "MoveConstructor:\t" << this << std::endl;
}
String::~String()
{
	delete[] this->str;
	std::cout << "Destructor:\t" << this << std::endl;
}

//	OPERATORS
String& String::operator=(const String& other)							//	=
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size];
	for (int i = 0; i < size; i++)	this->str[i] = other.str[i];
	std::cout << "CopyAssignment:\t" << this << std::endl;
	return *this;
}
String operator+(const String& str1, const String& str2)				//	+
{	/*String newstring(str1.get_size() + str2.get_size() - 1);
	strcat(newstring.get_str(), str1.get_str());
	strcat(newstring.get_str(), str2.get_str());
	return newstring;*/
	String cat(str1.get_size() + str2.get_size() - 1);
	for (int i = 0; i < str1.get_size(); i++)
	{
		cat[i] = str1[i];
	}
	for (int i = 0; i < str2.get_size(); i++)
	{
		cat[i + str1.get_size() - 1] = str2[i];
	}
	return cat;
}
String& String::operator+=(const String& other)							//	+=
{
	return *this = *this + other;
}
/*String& operator=(String&& source)
{	if (this == &source)return *this;
	delete[] this->str;
	this->size = source.size;
	this->str = new char[size];
	for (int i = 0; i < size; i++)	this->str[i] = source.str[i];
	std::cout << "MoveAssignment:\t" << this << std::endl;
	return *this;}*/
const char& String::operator[](int i) const								//	[] const
	//const char&   <--   ����������� ������ �� char	
	//const   <--   ����������� �����
{
	return str[i];
}
char& String::operator[](int i)											//	[]
{
	return str[i];
}
bool operator==(const String& left, const String& right)				//	==
{
	if (strlen(left.get_str()) != strlen(right.get_str()))return false;
	for (int i = 0; left[i]; i++)
	{
		if (left[i] != right[i])return false;
	}
	return true;
}
bool operator!=(const String& left, const String& right)				//	!=
{
	return !(left == right);
}
std::ostream& operator<<(std::ostream& os, const String& obj)			//	<<
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)					//	>>
{
	char* str = new char[20]{};
	is >> str;
	str = (char*)realloc(str, 30);
	obj.set_str(str);
	delete[] str;
	return is;
}
bool operator<(const String& left, const String& right)					//	<
{
	return strcmp(left.get_str(), right.get_str()) < 0 ? true : false;
}
bool operator>(const String& left, const String& right)					//	>
{
	return strcmp(left.get_str(), right.get_str()) > 0 ? true : false;
}

//		METHODS:
void String::print()
{
	std::cout << size << "\t" << str << std::endl;
}

////////////////////////////////////////////////////////////////////////////////////