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
private:
	void insert(int data, Element* root)
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
			else insert(data, root->pLeft);
		}
		else
		{
			if (root->pRight == nullptr) root->pRight = new Element(data);
			else insert(data, root->pRight);
		}
	}
	void erase(int v, Element*& root)
	{
		if (root == nullptr)return;
		if (v < root->data)
		{
			erase(v, root->pLeft);
		}
		else if (v > root->data)
		{
			erase(v, root->pRight);
		}
		else
		{
			if (root->pLeft == root->pRight)
			{
				//delete root;
				root = nullptr;
			}
			else if (size(root->pLeft)>size(root->pRight)) {
				root->data = maxValue(root->pLeft);
				erase(maxValue(root->pLeft), root->pLeft);
			}
			else
			{
				root->data = minValue(root->pRight);
				erase(minValue(root->pRight), root->pRight);
			}
		}
	}
	int sum(Element* root)const
	{
		if (root == nullptr)return 0;
		return sum(root->pLeft) + sum(root->pRight) + root->data;
	}
	int size(Element* root)const
	{
		if (root == nullptr)return 0;
		return size(root->pLeft) + size(root->pRight) + 1;
	}
	void print(Element* root)const
	{
		if (root == nullptr)return;
		print(root->pLeft);
		std::cout << root->data << "\t";
		print(root->pRight);
	}
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
	void erase(int v)
	{
		return erase(v, this->root);
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

	int size()const
	{
		return size(this->root);
	}
	int sum()const
	{
		
		return sum(this->root);
	}
	double avg()const
	{
		return double(sum(this->root))/size(this->root);
	}
	void print()
	{
		print(this->root);
		std::cout << std::endl;
	}

	
};

#define BASE_CHECK

void main() 
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	std::cout << "Input number of element: "; std::cin >> n;
	BTree T800;
	for (int i = 0; i < n; i++)
	{
		T800.insert(rand() % 100);
	}
	T800.print();

	std::cout << T800.size() << std::endl;
	std::cout << T800.sum() << std::endl;
	std::cout << T800.avg() << std::endl;
	std::cout << "Введите значение удаляемого значения: "; int v; std::cin >> v; std::cout << "\n";
	T800.erase(v);
	T800.print();
#endif // BASE_CHECK

	/*BTree doob;
	doob.insert(50);
	doob.insert(25);
	doob.insert(80);
	doob.insert(50);
	doob.insert(50);*/

	//std::cout << T800.minValue() << std::endl;
	//std::cout << T800.maxValue() << std::endl;
}