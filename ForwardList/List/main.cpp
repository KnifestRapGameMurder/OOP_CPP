#include"headers.h"



//#define BASE_CHECK
//#define CONSTRUCTORS_CHECK
//#define OPERATOR+CHECK 
//#define OPERATOR_PLUS_DOUBLE
#define OPERATOR_PLUS_STRING

void main()
{
	int n;
	//std::cout << "Input list size: "; std::cin >> n;
#ifdef BASE_CHECK
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	list.print_reverse();
	int index;
	int data;
	try
	{
		std::cout << "Input index: "; std::cin >> index;
		//std::cout << "Input value: "; std::cin >> data;
		//list.insert(index, data);
		list.erase(index);
		list.print();
		list.print_reverse();
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
#endif // BASE_CHECK

#ifdef CONSTRUCTORS_CHECK
	int arr[] = { 3, 5, 8 };

	List list = { 3, 5, 8, 13, 21 };
	list = list;
	list.print();
	list.print_reverse();

	List list2 = list;
	//list2 = list;
	list2.print();
	list2.print_reverse();
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR+CHECK
	int arr[] = { 3, 5, 8, 13, 21 };
	for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	List list = { 3, 5, 8, 13, 21 };
	//list.print();
	//list.print_reverse();

	for (List::Iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	List list2 = { 34,55,89 };
	for (List::Iterator it = list2.begin(); it != list2.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "\n----------------------------------------------------------------------\n";
	/*for (int i : list + list2)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;*/

	List list3;
	list3 = list + list2;
	//list3.print();
	for (int i : list3)
	{
		std::cout << i << "\t";
	}
	//std::cout << std::endl;
	std::cout << "\n----------------------------------------------------------------------\n";
	for (List::ReverseIterator rit = list3.rbegin(); rit != list3.rend(); rit++)
	{
		std::cout << *rit << "\t";
	}
	std::cout << std::endl;
#endif // OPERATOR+CHECK

#ifdef OPERATOR_PLUS_DOUBLE
	List<double> list1 = { 1,1,2,3,5,8 };
for (List<double>::Iterator it = list1.begin(); it != list1.end(); it++)
{
	std::cout << *it << "\t";
}
std::cout << std::endl;

List<double> list2 = { 34.4,55.6,89.32 };
for (int i : list2)
	std::cout << i << "\t";
std::cout << std::endl;

List<double> list3 = list1 + list2;
list3.print();
#endif // OPERATOR+_INT


#ifdef OPERATOR_PLUS_STRING
List<std::string> list1 = { "One","Two","Three" };
for (List<std::string>::Iterator it = list1.begin(); it != list1.end(); it++)
{
	std::cout << *it << "\t";
}
std::cout << std::endl;

List<std::string> list2 = { "Four","Five","Six" };
for (std::string i : list2)
std::cout << i << "\t";
std::cout << std::endl;

//List<std::string> list3 = list1 + list2;
//list3.print();
#endif // OPERATOR_PLUS_STRING


	/*List<double> list2 = { 1.34,1.34,2.54,3.2,5.7,8.2 };
	for (List<double>::Iterator it = list2.begin(); it != list2.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	List<std::string> list3 = { "Hello","World"};
	for (List<std::string>::Iterator it = list3.begin(); it != list3.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;*/

	
}	