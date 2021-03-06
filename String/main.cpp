#include<iostream>
#include<cstring>

class String;

String operator+(const String& str1, const String& str2);

class String
{
	int size;
	char* str;	//Number of bites
public:
	//	GET METHODS
	int get_size()const { return size; }
	const char* get_str()const { return str; }
	char* get_str() { return str; }
	//	SET METHODS
	void set_str(const char* str)
	{
		delete[] this->str;
		this->size = strlen(str)+1;
		this->str = new char[size] {};
		strcpy_s(this->str, this->size, str);
	}

	//		CONSTRUCTORS
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{	std::cout << "DefaultConstructor:\t" << this << std::endl;}

	String(const char* str) :String(strlen(str)+1)
	{	for (int i = 0; i < size; i++)	this->str[i] = str[i];
		std::cout << "Constructor:\t" << this << std::endl;}

	String(const String& other) :String(other.str)
	{	std::cout << "CopyConstructor:\t" << this << std::endl;}

	String(String&& other) :size(other.size), str(other.str)
	{	other.str = nullptr;
		std::cout << "MoveConstructor:\t" << this << std::endl;}

	~String(){	delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;}



	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size];
		for (int i = 0; i < size; i++)	this->str[i] = other.str[i];
		std::cout << "CopyAssignment:\t" << this << std::endl;
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	/*String& operator=(String&& source)
	{
		if (this == &source)return *this;
		delete[] this->str;
		this->size = source.size;
		this->str = new char[size];
		for (int i = 0; i < size; i++)	this->str[i] = source.str[i];
		std::cout << "MoveAssignment:\t" << this << std::endl;
		return *this;
	}*/

	const char& operator[](int i) const
		//	const char&   <--   ����������� ������ �� char
		//	const   <--   ����������� �����
	{
		return str[i];
	}

	char& operator[](int i)
	{
		return str[i];
	}

	//		Methods:
	void print()
	{
		std::cout << size << "\t" << str << std::endl;
	}
};

bool operator==(const String& left, const String& right)
{
	if (strlen(left.get_str()) != strlen(right.get_str()))return false;
	for(int i=0;left[i];i++)
	{
		if (left[i] != right[i])return false;
	}
	return true;
}
bool operator!=(const String& left, const String& right)
{
	return !(left == right);
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

std::istream& operator>>(std::istream& is,String& obj)
{
	char* str = new char[20] {};
	is >> str;
	str = (char*)realloc(str,30);
	obj.set_str(str);
	delete[] str;
	return is;
}

String operator+(const String& str1, const String& str2)
{

	/*String newstring(str1.get_size() + str2.get_size() - 1);
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

bool operator<(const String& left, const String& right)
{
	return strcmp(left.get_str(), right.get_str()) < 0 ? true : false;
}
bool operator>(const String& left, const String& right)
{
	return strcmp(left.get_str(), right.get_str()) > 0 ? true : false;
}

//#define BEGINNING
//#define CONCAT_AND_INPUT_CHECK
#define MOVE_CONSTRUCTOR_AND_ASSIGNMENT
//#define INPUT_CHECK
void main()
{
#ifdef BEGINNING
	String str1;
	str1.print();

	String str2 = "Hello";
	str2.print();

	String str3 = str2;
	str2.print();

	str1 = str2;
	str1.print();

	str2 = str2;
	std::cout << str2 << std::endl;
	/*str2.print();*/
#endif // BEGINNING

#ifdef CONCAT_AND_INPUT_CHECK
	String str1("Slava ");
	String str2;
	std::cout << "Input str2: ";
	std::cin >> str2;
	std::cout << std::endl;
	std::cout << "\n----------------------------\n";
	String str3 = str1 + str2;
	std::cout << "\n----------------------------\n";
	std::cout << str3 << std::endl;
#endif // CONCAT_AND_INPUT_CHECK

#ifdef MOVE_CONSTRUCTOR_AND_ASSIGNMENT

	String str1("Hello ");
	String str2("World");
	std::cout << "\n----------------------\n";
	std::cout << (str1+str2) << std::endl;
	std::cout << "\n----------------------\n";
#endif // MOVE_CONSTRUCTOR_AND_ASSIGNMENT
#ifdef INPUT_CHECK

	String str = "Hello";
	std::cout << str << std::endl;
	std::cin >> str;
	std::cout << str << std::endl;

#endif // INPUT_CHECK

	/*String str1 = "Hello";
	String str2 = "World";
	std::cout << (str1 < str2) << std::endl;*/
}