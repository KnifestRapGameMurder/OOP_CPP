#include<iostream>

#define DELIMITER std::cout<<"------------------------------------\n";

class Element {
	int Data;
	Element* pNext;		//
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		count--;
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;
	unsigned int Size;
public:
	ForwardList()
	{
		Head = nullptr;//Если список пуст , то его голова указывает на 0
		Size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~ForwardList()
	{
		std::cout << "LDestructor:\t" << this << std::endl;
	}
	//				Add elem
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		Size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head; //  Итератор - это указатель при помощи которого можно получить доступ к элементам структуры данных
		while (Temp->pNext != nullptr)
		{
			//std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
		Element* New = new Element(Data);
		Temp->pNext = New;
		Size++;
	}
	void pop_front()
	{
		Element* buffer = Head;	//Запоминаем адрес удаляемого элемента
		
		Head = Head->pNext;		//		Исключаем элемент из списка
		delete buffer;
		Size--;
	}
	void pop_back()
	{
		Element* Temp = Head; //  Итератор - это указатель при помощи которого можно получить доступ к элементам структуры данных
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;	//Переход на следующий элемент
		}
		Temp->pNext = nullptr;
		delete Temp->pNext;
		Size--;
	}

	void insert(int index, int Data)
	{
		if(index > Head->count)
		{
			std::cout << "Error: Out of range.!!!!\n";
			return;
		}
		Element* Temp = Head;
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		for (int i = 0; i < index-1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		Size++;
	}

	//				Methods
	void print()const
	{
		Element* Temp = Head; //  Итератор - это указатель при помощи которого можно получить доступ к элементам структуры данных
		while (Temp != nullptr)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
			
		}
		std::cout << "List size: " << Head->count << " elements.\n";
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Element e(5);
	int n;
	std::cout << "Input list size: "; std::cin >> n;

	ForwardList fl;
	
	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 200);
	}
	fl.push_back(1024);
	fl.print();
	/*DELIMITER
	fl.pop_back();
	fl.print();*/
	DELIMITER
	fl.insert(7,556);
	fl.print();

	ForwardList fl2;
	fl2.push_back(0);
	fl2.push_back(1);
	fl2.push_back(1);
	fl2.push_back(2);
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(13);
	
}