#include"Header.h"

//		LIST	begin	/////////////////////////////////////////////////////////////////////////////////
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

List::ReverseIterator List::rbegin()
{
	return this->tail;
}
List::ReverseIterator List::rend()
{
	return (ReverseIterator)nullptr;
}
const List::ReverseIterator List::rbegin()const
{
	return this->tail;
}
const List::ReverseIterator List::rend()const
{
	return (ReverseIterator)nullptr;
}

List operator+(const List& left, const List& right)
{
	List buf = left;
	for (List::Iterator it = right.begin(); it != right.end(); it++)	buf.pushBack(*it);
	std::cout << "Global operator +\n";
	return buf;
}
//		ELEMENT	begin	/////////////////////////////////////////////////
List::Element::Element(int data, Element* pNext, Element* pPrev) : data(data), pNext(pNext), pPrev(pPrev)
{
	std::cout << "EConstructor:\t" << this << std::endl;
}
List::Element::~Element()
{
	std::cout << "EDestructor:\t" << this << std::endl;
}
//		ELEMENT		end		/////////////////////////////////////////////
//		ITERATOR	begin	/////////////////////////////////////////////
List::Iterator::Iterator(Element* temp)
{
	this->temp = temp;
	std::cout << "ItConstructor:\t" << this << std::endl;
}
List::Iterator::~Iterator()
{
	std::cout << "ItDestructor:\t" << this << std::endl;
}
List::Iterator& List::Iterator::operator++()
{
	temp = temp->pNext;
	return *this;
}
List::Iterator& List::Iterator::operator++(int)
{
	Iterator old = *this;	//CopyConstructor 
	temp = temp->pNext;
	return old;
}
bool List::Iterator::operator==(const Iterator& other)const
{
	return (*this == other);
}
bool List::Iterator::operator!=(const Iterator& other)const
{
	return (temp != other.temp);
}
int& List::Iterator::operator*()
{
	return temp->data;
}
const int& List::Iterator::operator*()const
{
	return temp->data;
}
//		ITERATOR	end		/////////////////////////////////////////////
//		REVERSEITERATOR	begin	/////////////////////////////////////////
List::ReverseIterator::ReverseIterator(Element* temp)
{
	this->temp = temp;
	std::cout << "RitConstructor:\t" << this << std::endl;
}
List::ReverseIterator::~ReverseIterator()
{
	std::cout << "RitDestructor:\t" << this << std::endl;
}
List::ReverseIterator& List::ReverseIterator::operator++()
{
	temp = temp->pPrev;
	return *this;
}
List::ReverseIterator& List::ReverseIterator::operator++(int)
{
	ReverseIterator old = *this;	//CopyConstructor 
	temp = temp->pPrev;
	return old;
}
bool List::ReverseIterator::operator==(const ReverseIterator& other)const
{
	return (*this == other);
}
bool List::ReverseIterator::operator!=(const ReverseIterator& other)const
{
	return (temp != other.temp);
}
int& List::ReverseIterator::operator*()
{
	return temp->data;
}
const int& List::ReverseIterator::operator*()const
{
	return temp->data;
}
//		REVERSEITERATOR	end		/////////////////////////////////////////
//		LIST	end	//////////////////////////////////////////////////////////////////////////////////////