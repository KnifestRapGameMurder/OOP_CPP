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
		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr) : data(data), pNext(pNext), pPrev(pPrev)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class List;
	};

	Element* head;	// Сожнржит указатель на начало списка
	Element* tail;	// Указывает на конец списка
	unsigned int size;	// Количество элементов списка
public:
	List()
	{
		head = tail = nullptr;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~List()
	{
		while (head || tail)
		{
			popFront();
			popBack();
		}
		std::cout << "LDestructor:\t" << this << std::endl;
	}

	//			Methods: Adding elements
	void pushFront(int data)
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
	void pushBack(int data)
	{
		if (head == nullptr)
		{
			head = tail = new Element(data);
			size++;
			return;
		}
		tail = tail->pNext = new Element(data,nullptr,tail);
		size++;
	}

	//			Methods: Removeing elements
	void popFront()
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
	void popBack()
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
	void insert(int data, int index)
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
		else if (index > size ) return;
		else if (index <= size+1 / 2)
		{
			temp = head;
			
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->pNext;
			}
		}
		else {
			temp = tail;
			for (int i = size-1; i > index; i--)
			{
				temp = temp->pPrev;
			}
		}
		temp->pNext->pNext->pPrev=temp->pNext = new Element(data, temp->pNext,temp);
		size++;
	}
	void erase(int index)
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
		else if (index > size) return;
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
	void print()const
	{
		for (Element* Temp = head; Temp != nullptr; Temp = Temp->pNext)
		{
			std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
		}
		std::cout << "List size:\t" << size << std::endl;
	}
	void printReverse()const
	{
		for (Element* Temp = tail; Temp != nullptr; Temp = Temp->pPrev)
		{
			std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
		}
		std::cout << "List size:\t" << size << std::endl;
	}
};


void main() {
	setlocale(LC_ALL, "");
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
	list.insert(333, index);
	list.print();
	list.printReverse();
	std::cout << "Input index: "; std::cin >> index;
	list.erase(index);
	list.print();
	list.printReverse();

}

