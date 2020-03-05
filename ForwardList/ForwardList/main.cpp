#include<iostream>

class Element {
	int Data;
	Element* pNext;		//
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		Head = nullptr;//Если список пуст , то его голова указывает на 0
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
	}
	void pop_back()
	{
		
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
}