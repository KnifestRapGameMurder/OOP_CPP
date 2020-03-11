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
	unsigned int get_size()
	{
		return Size;
	}
	ForwardList()
	{
		Head = nullptr;//Если список пуст , то его голова указывает на 0
		Size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	ForwardList(int Size) :ForwardList()
	{
		/*for (int i = 0; i < size; i++)
		{
			this->push_front(0);
		}*/
		while (Size--)push_front(0);
		std::cout << "LConstructor/wSize:\t" << this << std::endl;
	}
	ForwardList(const std::initializer_list<int>& il) :ForwardList()
	{	
		for (const int* it = il.begin(); it != il.end(); it++)
		{	
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		Element* Temp = other.Head->pNext;
		push_front(0);
		for (int i = 0; i < other.Size-1; i++)
		{
			push_back(0);
			Head->pNext->Data = Temp->Data;
		}
		std::cout << "LCopyConstructor:\t" << this << std::endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		std::cout << "LDestructor:\t" << this << std::endl;
	}
	//				Add elem
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		Size++;*/
		Head = new Element(Data, Head);
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
		Temp->pNext = new Element(Data);
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
		Temp->pNext = new Element(Data,Temp->pNext);
		Size++;
	}
	void erase(int index)
	{
		if (index > Head->count)
		{
			std::cout << "Error: Out of range.!!!!\n";
			return;
		}
		if (index == 0)
		{
			pop_front();
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* buffer = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;	//
		delete buffer;
		Size--;
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
		std::cout << "List size: " << Size << " elements.\n";
	}

	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index;i++)Temp = Temp->pNext;
		return Temp->Data;
	}
};

//#define FIRST_LESSON
//#define CONSTR_CHECK_1
#define CONSTR_CHECK_2

void main()
{
	setlocale(LC_ALL, "");
	//Element e(5);

#ifdef CONSTR_CHECK_1
	int n = 0;
	std::cout << "Input size: "; std::cin >> n;
	ForwardList fl(n);
	fl.push_back(3);
	fl.push_back(5);
	fl.push_back(8);
	fl.push_back(13);
	fl.print();
	DELIMITER;
	for (int i = 0; i < fl.get_size(); i++)
	{
		fl[i] = rand() % 100;
	}
	for (int i = 0; i < fl.get_size(); i++)
	{
		std::cout << fl[i] << "\t";
	}
#endif // CONSTR_CHECK_1


#ifdef FIRST_LESSON
	int n;
	std::cout << "Input list size: "; std::cin >> n;

	ForwardList fl;

	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 200);
	}
	//fl.push_back(1024);
	//fl.print();
	///*DELIMITER
	//fl.pop_back();
	//fl.print();*/
	//DELIMITER
	//fl.insert(7,556);
	fl.print();
	fl.erase(3);
	fl.print();

	/*ForwardList fl2;
	fl2.push_back(0);
	fl2.push_back(1);
	fl2.push_back(1);
	fl2.push_back(2);
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(13);*/
#endif // FIRST_LESSON

#ifdef CONSTR_CHECK_2
	
#endif // CONSTR_CHECK_2

	ForwardList list = { 3,5,8,13,21 };
	for (int i = 0; i < list.get_size(); i++)
	{
		std::cout << list[i] << "\t";
	}
	std::cout << std::endl;
}