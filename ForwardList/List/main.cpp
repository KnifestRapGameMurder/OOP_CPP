#include"Header.h"

//#define BASE_CHECK
//#define CONSTRUCTORS_CHECK
//#define RANGE-BASED_FOR

void main() {
	setlocale(LC_ALL, "");
	
#ifdef BASE_CHECK
	int n;
	std::cout << "Input list size: "; std::cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.pushBack(rand() % 100);
	}
	list.print();
	//list.printReverse();
	DELIM;
	list.pushBack(555);
	list.pushBack(777);
	list.print();
	list.popFront();
	list.print();
	list.popBack();
	list.print();
	int index;
	std::cout << "Input index: "; std::cin >> index;
	std::cout << "\n____INSERT____\n";
	list.insert(333, index);
	list.print();
	list.printReverse();
	std::cout << "Input index: "; std::cin >> index;
	std::cout << "\n____ERASE____\n";
	list.erase(index);
	list.print();
	list.printReverse();
#endif // BASE_CHECK

#ifdef CONSTRUCTORS_CHECK
	List list = { 3,5,8,13,21 };
	list.print();
	list.printReverse();
	DELIM;
	List list2 = list;
	list2.print();
	list2.printReverse();
#endif // CONSTRUCTORS_CHECK

#ifdef RANGE-BASED_FOR
	List list = { 3,5,8,13,21 };
	for (List::ReverseIterator i = list.rbegin();i!=list.rend();i++ )
	{
		std::cout << i << "\t";
	}
	std::cout << "\n";
#endif // RANGE-BASED_FOR

	/*List l1 = { 1,1,2,3,5 };
	List l2 = { 8,13,21,34,55 };
	List l3 = l1 + l2;
	l3.print();
	l3.printReverse();*/

	/*List l1 = { 1,1,2,3,5 };
	List l2 = { 8,13,21,34,55 };
	List l3;
	l3 = l1 + l2;
	l3.print();
	l3.printReverse();*/
	 
	List list = {3,5,8,13};
	
	for (List::ReverseIterator rit = list.rbegin(); rit != list.rend(); rit++)
	{
		std::cout << *rit << "\t";
	}
	std::cout << std::endl;
}

