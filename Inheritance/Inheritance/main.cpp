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
	{	std::cout << "BoxDestructor" << this << std::endl;}

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

void main()
{
	Box box1(1.2, 2.3, 3.4);

}