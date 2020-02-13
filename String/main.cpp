#include"String.h"

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