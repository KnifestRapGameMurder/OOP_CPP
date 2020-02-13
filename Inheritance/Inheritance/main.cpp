#include<iostream>

class Box
{
	double width;
	double height;
	double length;
	bool closed;
public:
			//	Constructors:
	Box(double width=2,double length=2, double height=1) :width(width),length(length), height(height), closed(true)
	{	std::cout << "BoxConstructor:\t" << this << std::endl;}
	~Box()
	{	std::cout << "BoxDestructor:\t" << this << std::endl;}

			//	Methods:
	void open()
	{	closed = false;
	}
	void close()
	{
		closed = true;
	}

	void get_status()const
	{
		std::cout << "Box is " << (closed ? "closed" : "open") << std::endl;
	}
};

class GiftBox :public Box
{

};

void main()
{
	Box box1(1.2, 2.3, 3.4);
	box1.open();
	box1.get_status();
	box1.close();
	box1.get_status();

	GiftBox box2;
	box2.get_status();
}