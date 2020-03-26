#include<iostream>

#define DELIM	std::cout<<"\n________________________________________________\n"

class List
{
	class Element
	{
		int data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int data, Element* pNext, Element* pPrev);
		~Element();
		friend class List;
	};

	Element* head;	// Сожнржит указатель на начало списка
	Element* tail;	// Указывает на конец списка
	unsigned int size;	// Количество элементов списка
public:

	class Iterator
	{
		Element* temp;
	public:
		Iterator(Element* temp)
		{
			this->temp = temp;
			std::cout << "ItConstructor:\t" << this << std::endl;
		}
		~Iterator() { std::cout << "ItDestructor:\t" << this << std::endl; }

		Iterator& operator++()
		{
			temp = temp->pNext;
			return *this;
		}
		Iterator& operator++(int)
		{
			Iterator old = *this;	//CopyConstructor 
			temp = temp->pNext;
			return old;
		}

		bool operator==(const Iterator& other)const
		{
			return (*this == other);
		}
		bool operator!=(const Iterator& other)const
		{
			return (temp != other.temp);
		}

		int& operator*()
		{
			return temp->data;
		}
		const int& operator*()const
		{
			return temp->data;
		}
	};
	
	List();
	List(const std::initializer_list<int>& il);
	List(const List& other);
	List(List&& other);
	~List();

	//			Methods: Adding elements
	void pushFront(int data);
	void pushBack(int data);
	//			Methods: Removeing elements
	void popFront();
	void popBack();
	void insert(int data, int index);
	void erase(int index);
	//			Methods: 
	void print()const;
	void printReverse()const;

	List& operator=(const List& other);
	List& operator=(List&& other);

	Iterator begin();
	Iterator end();

	const Iterator begin()const;
	const Iterator end()const;
	
};
//		LIST	begin	/////////////////////////////////////
List::List()
{
	head = tail = nullptr;
	std::cout << "LConstructor:\t" << this << std::endl;
}
List::List(const std::initializer_list<int>& il) :List()
{
	for (int const* it = il.begin(); it != il.end(); it++)
	{
		pushBack(*it);
	}
}
List::List(const List& other) :List()
{
	//for (Element* temp = other.head; temp != nullptr; temp = temp->pNext)	pushBack(temp->data);
	for (Iterator it = other.head; it != nullptr; it++)	pushBack(*it);
	std::cout << "LCopyConstructor:\t" << this << std::endl;
}
List::List(List&& other)
{
	this->head = other.head;
	this->tail = other.tail;
	this->size = other.size;
	other.head = other.tail = nullptr;
	std::cout << "LMoveConstructor:\t" << this << std::endl;
}
List::~List()
{
	while (head || tail)
	{
		popFront();
		popBack();
	}
	std::cout << "LDestructor:\t" << this << std::endl;
}

//			Methods: Adding elements
void List::pushFront(int data)
{
	if (head == nullptr)
	{
		head = tail = new Element(data);
		size++;
		return;
	}
	head = head->pPrev = new Element(data, head);
	size++;
}
void List::pushBack(int data)
{
	if (head == nullptr)
	{
		head = tail = new Element(data);
		size++;
		return;
	}
	tail = tail->pNext = new Element(data, nullptr, tail);
	size++;
}
//			Methods: Removeing elements
void List::popFront()
{
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		if (size)size--;
		return;
	}
	head = head->pNext;
	delete head->pPrev;
	head->pPrev = nullptr;
	size--;
}
void List::popBack()
{
	if (head == tail)
	{
		popFront();
		return;
	}
	//tail->pPrev->pNext = tail->pNext;
	tail = tail->pPrev;
	delete tail->pNext;
	tail->pNext = nullptr;
	size--;
}
void List::insert(int data, int index)
{
	Element* temp;
	if (index == 0)
	{
		pushFront(data);
		return;
	}
	else if (index == size)
	{
		pushBack(data);
		return;
	}
	else if (index >= size) return;
	else if (index <= size + 1 / 2)
	{
		temp = head;

		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->pNext;
		}
	}
	else {
		temp = tail;
		for (int i = size - 1; i > index; i--)
		{
			temp = temp->pPrev;
		}
	}
	temp->pNext->pNext->pPrev = temp->pNext = new Element(data, temp->pNext, temp);
	size++;
}
void List::erase(int index)
{
	Element* temp;
	if (index == 0)
	{
		popFront();
		return;
	}
	else if (index == size)
	{
		popBack();
		return;
	}
	else if (index >= size) throw std::exception("Error: Out of range");
	else if (index <= size + 1 / 2)
	{
		temp = head;

		for (int i = 0; i < index; i++)
		{
			temp = temp->pNext;
		}
	}
	else {
		temp = tail;
		for (int i = size; i > index; i--)
		{
			temp = temp->pPrev;
		}
	}
	temp->pPrev->pNext = temp->pNext;
	temp->pNext->pPrev = temp->pPrev;
	delete temp;
	size--;
}
//			Methods: 
void List::print()const
{
	for (Element* Temp = head; Temp != nullptr; Temp = Temp->pNext)
	{
		std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
	}
	std::cout << "List size:\t" << size << std::endl;
}
void List::printReverse()const
{
	for (Element* Temp = tail; Temp != nullptr; Temp = Temp->pPrev)
	{
		std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
	}
	std::cout << "List size:\t" << size << std::endl;
}

List& List::operator=(const List& other)
{
	if (this == &other)	return *this;
	while (head)popFront();
	for (Element* temp = other.head; temp; temp = temp->pNext)	pushBack(temp->data);
	std::cout << "LCopyAssignment:\t" << this << std::endl;
	return *this;
}
List& List::operator=(List&& other)
{
	while (head)popFront();
	this->head = other.head;
	this->tail = other.tail;
	this->size = other.size;
	other.head = other.tail = nullptr;
	std::cout << "LMoveAssignment:\t" << this << std::endl;
	return *this;
}

List::Iterator List::begin()
{
	return this->head;
}
List::Iterator List::end()
{
	return (Iterator)nullptr;
}

const List::Iterator List::begin()const
{
	return this->head;
}
const List::Iterator List::end()const
{
	return (Iterator)nullptr;
}

List operator+(const List& left, const List& right)
{
	List buf = left;
	for (List::Iterator it = right.begin(); it != right.end(); it++)	buf.pushBack(*it);
	std::cout << "Global operator +\n";
	return buf;
}

List::Element::Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr) : data(data), pNext(pNext), pPrev(pPrev)
{
	std::cout << "EConstructor:\t" << this << std::endl;
}
List::Element::~Element()
{
	std::cout << "EDestructor:\t" << this << std::endl;
}

//		LIST	end	/////////////////////////////////////


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
	for (int i : list)
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

	List l1 = { 1,1,2,3,5 };
	List l2 = { 8,13,21,34,55 };
	List l3;
	l3 = l1 + l2;
	l3.print();
	l3.printReverse();

}

