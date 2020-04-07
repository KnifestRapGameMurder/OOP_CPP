#pragma once

#include<iostream>
template<typename T>
class List
{
	class Element
	{
		T data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(T data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
	};

	Element* head;
	Element* tail;
	unsigned int size;

public:

	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr);
		~Iterator();

		//		Operators:
		Iterator& operator++();;
		Iterator operator++(int);

		const T& operator*()const;
		T& operator*();

		bool operator==(const Iterator& other)const;
		bool operator!=(const Iterator& other)const;


	};//	calss Iterator [end]

	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr);
		~ReverseIterator();

		//		Operators:
		ReverseIterator& operator++();
		ReverseIterator operator++(int);

		const T& operator*()const;
		T& operator*();

		bool operator==(const ReverseIterator& other)const;
		bool operator!=(const ReverseIterator& other)const;
	};//	calss ReverseIterator [end]


	//{{{{{{{{{{{{{{{{{{{{{{{{{{{begin	//		begin(rbegin)&end(rend)-methods		//		//
	const Iterator begin()const;
	const Iterator end()const;
	const ReverseIterator rbegin()const;
	const ReverseIterator rend()const;
	Iterator begin();
	Iterator end();
	ReverseIterator rbegin();
	ReverseIterator rend();
	//}}}}}}}}}}}}}}}}}}}}}}}}}}}end	//		begin(rbegin)&end(rend)-methods		//		//

	//		List-constructors:
	List();
	List(const std::initializer_list<T>& il);
	List(const List<T>& other) :List<T>();
	List(List<T>&& other);
	~List();
	//			Operators:
	List<T>& operator=(const List<T>& other);
	List<T>& operator=(List<T>&& other);
	//			Adding elements:
	void push_front(T data);
	void push_back(T data);
	void insert(int index, T data);
	//			Removing elements:
	void pop_front();
	void pop_back();

	void erase(int index);

	//			Methods:
	void print()const;
	void print_reverse()const;
};//---------------------------------------------------------------calss List-----------------------------------------------------------[end]
