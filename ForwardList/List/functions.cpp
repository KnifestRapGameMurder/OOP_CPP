#include"headers.h"

//+++++++++++++++++++++++++++++++++LIST METHODS+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[begin]
template<typename T>
List<T>::List()
{
	head = tail = nullptr;
	size = 0;
	std::cout << "LConstructor:\t" << this << std::endl;
}
template<typename T>
List<T>::List(const std::initializer_list<T>& il) :List<T>()//																			LIST
{
	std::cout << typeid(il.begin()).name() << std::endl;
	/*for (int const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}*/
	for (T i : il)
	{
		push_back(i);
	}
}
template<typename T>
List<T>::List(const List<T>& other) :List<T>()
{
	/*for (Element* Temp = other.head; Temp; Temp = Temp->pNext)
	{
		push_back(Temp->data);
	}*/
	for (Iterator it = other.head; it != nullptr; it++)
		push_back(*it);
	std::cout << "LCopyConstructor:\t" << this << std::endl;
}
template<typename T>
List<T>::List(List<T>&& other)																	//										LIST
{
	this->head = other.head;
	this->tail = other.tail;
	this->size = other.size;
	other.head = other.tail = nullptr;
	std::cout << "LMoveConstructor:\t" << this << std::endl;
}
template<typename T>
List<T>::~List()
{
	while (head || tail)
	{
		pop_front();
		pop_back();
	}
	std::cout << "LDestructor:\t" << this << std::endl;
}
//			Operators:																													LIST
template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)return *this;
	while (head)pop_front();
	for (Element* Temp = other.head; Temp; Temp = Temp->pNext)push_back(Temp->data);
	std::cout << "LCopyAssignment:\t" << this << std::endl;
	return *this;
}
template<typename T>
List<T>& List<T>::operator=(List<T>&& other)
{
	while (head)pop_front();
	this->head = other.head;
	this->tail = other.tail;
	this->size = other.size;
	other.head = other.tail = nullptr;
	std::cout << "LMoveConstructor:\t" << this << std::endl;
	return *this;
}
//			Adding elements:																											LIST
template<typename T>
void List<T>::push_front(T data)
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
template<typename T>
void List<T>::push_back(T data)//																										LIST
{
	if (tail == nullptr)
	{
		head = tail = new Element(data);
		size++;
		return;
	}
	tail = tail->pNext = new Element(data, nullptr, tail);
	size++;
}
template<typename T>
void List<T>::insert(int index, T data)//																								LIST
{
	if (index > size)throw std::exception("Error: out of range");
	Element* Temp;
	if (index < size / 2)
	{
		Temp = head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = tail;
		for (int i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
	}

	/*Element* New = new Element(data);
	New->pNext = Temp;
	New->pPrev = Temp->pPrev;
	Temp->pPrev->pNext = New;
	Temp->pPrev = New;*/

	Temp->pPrev = Temp->pPrev->pNext = new Element(data, Temp, Temp->pPrev);
	size++;
}
//			Removing elements:																											LIST																				
template<typename T>
void List<T>::pop_front()
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
template<typename T>
void List<T>::pop_back()			//																									LIST
{
	if (head == tail)
	{
		delete tail;
		head = tail = nullptr;
		if (size)size--;
		return;
	}
	tail = tail->pPrev;
	delete tail->pNext;
	tail->pNext = nullptr;
	size--;
}
template<typename T>
void List<T>::erase(int index)//																										LIST
{
	if (index >= size)throw std::exception("Error: Out of range");
	if (index == 0)
	{
		pop_front();
		return;
	}
	if (index == size - 1)
	{
		pop_back();
		return;
	}

	Element* Temp;
	if (index < size / 2)
	{
		Temp = head;
		for (int i = 0; i < index; i++)Temp = Temp->pNext;
	}
	else
	{
		Temp = tail;
		for (int i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
	}

	Temp->pPrev->pNext = Temp->pNext;
	Temp->pNext->pPrev = Temp->pPrev;
	delete Temp;
	size--;
}
//			Methods:																													LIST
template<typename T>
void List<T>::print()const
{
	for (Element* Temp = head; Temp != nullptr; Temp = Temp->pNext)
	{
		std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
	}
	std::cout << "List size:\t" << size << std::endl;
}
template<typename T>
void List<T>::print_reverse()const
{
	for (Element* Temp = tail; Temp != nullptr; Temp = Temp->pPrev)
	{
		std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
	}
	std::cout << "List size:\t" << size << std::endl;
}
//+++++++++++++++++++++++++++++++++LIST METHODS+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[end]

//+++++++++++++++++++++++++++++++++ELEMENT METHODS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[begin]
template<typename T>
List<T>::Element::Element(T data, Element* pNext, Element* pPrev) :data(data), pNext(pNext), pPrev(pPrev)
{
	std::cout << "EConstructor:\t" << this << std::endl;
}
template<typename T>
List<T>::Element::~Element()
{
	std::cout << "EDestructor:\t" << this << std::endl;
}
//+++++++++++++++++++++++++++++++++ELEMENT METHODS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[end]

//+++++++++++++++++++++++++++++++++ITERATOR METHODS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[begin]
template<typename T>
List<T>::Iterator::Iterator(Element* Temp)
{
	this->Temp = Temp;

#ifdef DEBUG
	std::cout << "ItConstructor:\t" << this << std::endl;
#endif // DEBUG


}
template<typename T>
List<T>::Iterator::~Iterator()
{

#ifdef DEBUG
	std::cout << "ItDestructor:\t" << this << std::endl;
#endif // DEBUG


}
//		Operators:
template<typename T>
List<T>::Iterator& List<T>::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
template<typename T>
List<T>::Iterator List<T>::Iterator::operator++(int)
{
	Iterator old = *this;	//CopyConstructor
	Temp = Temp->pNext;
	return old;
}
template<typename T>
const T& List<T>::Iterator::operator*()const
{
	return Temp->data;
}
template<typename T>
T& List<T>::Iterator::operator*()
{
	return Temp->data;
}
template<typename T>
bool List<T>::Iterator::operator==(const Iterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>
bool List<T>::Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}
//+++++++++++++++++++++++++++++++++ITERATOR METHODS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[end]

//+++++++++++++++++++++++++++++++++REVERSE-ITERATOR METHODS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[begin]
template<typename T>
List<T>::ReverseIterator::ReverseIterator(Element* Temp)
{
	this->Temp = Temp;
#ifdef DEBUG
	std::cout << "RItConstructor:\t" << this << std::endl;
#endif // DEBUG
}
template<typename T>
List<T>::ReverseIterator::~ReverseIterator()
{
#ifdef DEBUG
	std::cout << "RItDestructor:\t" << this << std::endl;
#endif // DEBUG
}

//		Operators:
template<typename T>
List<T>::ReverseIterator& List<T>::ReverseIterator::operator++()
{
	Temp = Temp->pPrev;
	return *this;
}
template<typename T>
List<T>::ReverseIterator List<T>::ReverseIterator::operator++(int)
{
	ReverseIterator old = *this;
	Temp = Temp->pPrev;
	return old;
}
template<typename T>
const T& List<T>::ReverseIterator::operator*()const
{
	return Temp->data;
}
template<typename T>
T& List<T>::ReverseIterator::operator*()
{
	return Temp->data;
}
template<typename T>
bool List<T>::ReverseIterator::operator==(const ReverseIterator& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>
bool List<T>::ReverseIterator::operator!=(const ReverseIterator& other)const
{
	return this->Temp != other.Temp;
}
//+++++++++++++++++++++++++++++++++REVERSE-ITERATOR METHODS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[end]

//+++++++++++++++++++++++++++BEGIN - END - RBEGIN - REND++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[begin]
template<typename T>
const List<T>::Iterator List<T>::begin()const
{
	return this->head;
}
template<typename T>
const List<T>::Iterator List<T>::end()const
{
	return nullptr;
}
template<typename T>
const List<T>::ReverseIterator List<T>::rbegin()const
{
	return tail;
}
template<typename T>
const List<T>::ReverseIterator List<T>::rend()const
{
	return head->pPrev;
}
template<typename T>
List<T>::Iterator List<T>::begin()
{
	return this->head;
}
template<typename T>
List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>
List<T>::ReverseIterator List<T>::rbegin()
{
	return tail;
}
template<typename T>
List<T>::ReverseIterator List<T>::rend()
{
	return head->pPrev;
}
//+++++++++++++++++++++++++++BEGIN - END - RBEGIN - REND++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[end]


template<typename T>
List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> Buf = left;
	/*for (List<T>::Iterator it =
	right.begin();
	it != right.end();
	it++)
	{
	Buf.push_back(*it);

	}*/
	for (T i : right)Buf.push_back(i);
	std::cout << "Global operator +\n";
	return Buf;
}