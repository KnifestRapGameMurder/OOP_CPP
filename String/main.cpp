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

	//		CONSTRUCTORS
	String(int size = 80) :size(size), str(new char[size] {})
	{
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}

	String(const char* str) :size(strlen(str) + 1), str(new char[size] {})
	{
		for (int i = 0; i < size; i++)	this->str[i] = str[i];
		std::cout << "Constructor:\t" << this << std::endl;
	}

	String(const String& other) :String()
	{
		for (int i = 0; i < size; i++)	this->str[i] = other.str[i];
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}

	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		std::cout << "MoveConstructor:\t" << this << std::endl;
	}

	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}



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
		//	const char&   <--   константная ссылка на char
		//	const   <--   константный метод
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

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

std::istream& operator>>(std::istream& os, const String& obj)
{
	return os >> obj.get_str();
}

String operator+(const String& str1, const String& str2)
{

	/*String newstring(str1.get_size() + str2.get_size() - 1);
	strcat(newstring.get_str(), str1.get_str());
	strcat(newstring.get_str(), str2.get_str());
	return newstring;*/

	String cat = str1.get_size() + str2.get_size() - 1;
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

//#define BEGINNING
#define CONCAT
//#define MOVE_CONSTRUCTOR_AND_ASSIGNMENT
int main()
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

#ifdef CONCAT
	String str1("slava");
	String str2("Ukraini");
	std::cout << "\n----------------------------\n";
	String str3 = str1 + str2;
	std::cout << "\n----------------------------\n";
	std::cout << str3 << std::endl;
#endif // CONCAT

#ifdef MOVE_CONSTRUCTOR_AND_ASSIGNMENT

	String str1 = String("Ukr");
	std::cout << str1 << std::endl;
#endif // MOVE_CONSTRUCTOR_AND_ASSIGNMENT
	return 1;
}


