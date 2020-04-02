#include<iostream>

class BTree
{
	class Element
	{
		int data;
		Element* pLeft;
		Element* pRight;
	public:
		
		Element(int data, Element* pLeft = nullptr, Element* pRight = nullptr) :data(data), pLeft(pLeft), pRight(pRight)
		{
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class BTree;
	}*root;
public:
	Element* getRoot()
	{
		return this->root;
	}
	BTree() :root(nullptr)
	{
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~BTree()
	{
		clear(this->root);
		std::cout << "TDestructor:\t" << this << std::endl;
	}

	//+++++++++++Adding Elements++++++++++//

	void insert(int data)
	{
		insert(data, this->root);
	}

	void insert(int data,Element* root)
	{
		if (this->root == nullptr)//Если дерево пустое, то добавляем элемент прямо в корень.
		{
			this->root = new Element(data);
			return;
		}
		if (root == nullptr)return;
		if (data < root->data)
		{
			if (root->pLeft == nullptr)root->pLeft = new Element(data);
		}
		else
		{
			if (root->pRight == nullptr) root->pRight = new Element(data);
			else insert(data, root->pRight);
		}
	}

	void clear()
	{
		clear(this->root);
		this->root = nullptr;
	}

	void clear(Element* root)
	{
		if (root == nullptr)return;
		clear(root->pLeft);
		clear(root->pRight);
		delete root;
	}

	int minValue()
	{
		return minValue(this->root);
	}
	int minValue(Element* root)const
	{
		if (root->pLeft == nullptr)return root->data;
		minValue(root->pLeft);
		
	}
	int maxValue()
	{
		return maxValue(this->root);
	}
	int maxValue(Element* root)const
	{
		if (root->pRight == nullptr)return root->data;
		maxValue(root->pRight);

	}

	void print()
	{
		print(this->root);
		std::cout << std::endl;
	}

	void print(Element* root)const
	{
		if (root == nullptr)return;
		print(root->pLeft);
		std::cout << root->data << "\t";
		print(root->pRight);
	}
};

void main() 
{
	int n;
	std::cout << "Input number of element: "; std::cin >> n;

	BTree T800;
	for (int i = 0; i < n; i++)
	{
		T800.insert(rand(), T800.getRoot());
	}
	T800.print();
	
	std::cout << T800.minValue() << std::endl;
	std::cout << T800.maxValue() << std::endl;
}