#pragma once

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
		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr);
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
		Iterator(Element* temp);
		~Iterator();
		Iterator& operator++();
		Iterator& operator++(int);
		bool operator==(const Iterator& other)const;
		bool operator!=(const Iterator& other)const;
		int& operator*();
		const int& operator*()const;
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

List operator+(const List& left, const List& right);