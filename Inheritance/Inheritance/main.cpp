#include<iostream>

class Box
{
	double width;
	double height;
	double length;
	bool closed;
public:
			//	Constructors:
	Box(double width,double length, double height) :width(width),length(length), height(height), closed(true)
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
	std::string color;
	bool bant;
public:
	GiftBox(double width, double length, double height, std::string color) :Box(width,length,height)
	{
		std::cout << "GBConstructor:\t" <<this<< std::endl;
	}
	~GiftBox()
	{
		std::cout << "GBDestructor:\t" <<this<< std::endl;
	}
};

void main()
{
	Box box1(1.2, 2.3, 3.4);
	box1.open();
	box1.get_status();
	box1.close();
	box1.get_status();

	GiftBox box2(2,2,1,"green");
	box2.get_status();
}