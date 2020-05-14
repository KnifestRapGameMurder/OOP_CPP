#include<iostream>
#include<list>
#include<string>

class Shape
{
public:
	int n_of_sides;
	double P;
	double S;
	std::string color;

	Shape():n_of_sides(0),P(0),S(0),color("clear")	{	}
	Shape(int n_of_sides, std::string color) :n_of_sides(n_of_sides), color(color),P(0),S(0) {	}
	~Shape(){	}
};

class Triangle : public Shape
{
public:

	double first_angle;
	double second_angle;
	double third_angle;

	double a;
	double b;
	double c;

	Triangle(){
		n_of_sides = 3;
		first_angle = second_angle = third_angle = 60;
		a = b = c = 1;
	}
	Triangle(
		double a, double b,double first_angle,std::string color)
		:Shape(3,color),a(a),b(b),first_angle(first_angle)
	{
		c = sqrt(
			a * a + b * b
			- 2 * a * b * cos(first_angle)
		);
		third_angle = a * first_angle / b;
		second_angle = 180 - first_angle - third_angle;
		P = a + b + c;
		double p = P / 2;
		S = sqrt(p*(p-a)*(p-b)*(p-c));
	}
	~Triangle(){}
};

class RegularTriangle :public Triangle
{
public:
	RegularTriangle(){
		first_angle = second_angle = third_angle = 60;
	}
	RegularTriangle(double a,std::string color)
		:Triangle(a,a,60,color){	}
	~RegularTriangle(){}
};

class IsoscelesTriangle :public Triangle
{
public:
	IsoscelesTriangle()
	{
		third_angle = second_angle = (180 - first_angle)/2;
	}
	IsoscelesTriangle(double a, double c, double second_angle, std::string color)
		:Triangle(a, a, (180 - second_angle) / 2, color) {	}
	~IsoscelesTriangle(){	}
};

class RightTriangle :public Triangle
{
public:
	RightTriangle()
	{
		third_angle = 90;
		second_angle = third_angle = 45;
	}
	RightTriangle(double a, double c, double second_angle, std::string color)
		:Triangle(a, sqrt(a* a + c * c), 90, color)
	{
		this->c = c;
		this->second_angle = second_angle;
		this->third_angle = 90 - second_angle;
	}
	~RightTriangle(){	}
};

//--------------------------------- 

class Quadrangle : public Shape
{
public:
	double first_angle;
	double second_angle;
	double third_angle;
	double fourth_angle;

	double a;
	double b;
	double c;
	double d;

	Quadrangle()
	{
		first_angle = second_angle = third_angle = fourth_angle = 0;
		a = b = c = d = 0;
	}
	Quadrangle(
		double a, double b, double c, double d,
		double first_angle, double second_angle, double third_angle, std::string color)
		:Shape(4, color),a(a),b(b),c(c),d(d),
		first_angle(first_angle),second_angle(second_angle),third_angle(third_angle)
	{
		fourth_angle = 360 - first_angle - second_angle - third_angle;
		P = a + b + c + d;
		S = 0.5 * a * b * sin(second_angle) + 0.5 * c * d * sin(fourth_angle);
	}
	~Quadrangle() {	}
};

class Rectangle :public Quadrangle
{
public:
	Rectangle()
	{
		first_angle = second_angle = third_angle = fourth_angle = 90;
		a = c = 1;
		b = d = 2;
	}
	Rectangle(double a, double b, std::string color)
		:Quadrangle(a,b,a,b,
			90,90,90,color){ 
		S = a * b;
	}
	~Rectangle(){}
};

class Square :public Rectangle
{
public:
	double diagonal;

	Square(){
		b = d = 1;
		diagonal = a * sqrt(2);
	}
	Square(double a, std::string color)
		:Rectangle(a, a, color){
		S = a * a;
	}
	~Square(){}
};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram()
	{
		first_angle = third_angle = 30;
		second_angle = fourth_angle = 60;
		a = c = 1;
		b = d = 2;
	}
	Parallelogram(double a, double b,
		double first_angle, double second_angle, std::string color)
		: Quadrangle(a, b, a, b,
			first_angle, second_angle, first_angle, color){
		S = a * d * sin(first_angle);
	}
	~Parallelogram(){}
};

class Rhombus :public Parallelogram
{
public:
	Rhombus() {
		a = b = c = d = 1;
	}
	Rhombus(double a, double first_angle, double second_angle, std::string color)
		:Parallelogram(a,a,first_angle,second_angle,color){	}
	~Rhombus(){}
};

class Trapeze : public Quadrangle
{
public:
	Trapeze() {
		a = b = c = 2;
		d = 3;
		first_angle = fourth_angle = 30;
		second_angle = third_angle = 60;
	}
	Trapeze(double a, double b, double d,
		double first_angle, double second_angle, double third_angle, std::string color)
		:Quadrangle(a,b,a,d,first_angle,second_angle,third_angle,color){
		S = a * sin(first_angle) * (b - cos(first_angle));
	}
	~Trapeze(){}
};

class RectangularTrapezoid : public Trapeze
{
public:
	RectangularTrapezoid() {
		first_angle = second_angle = 90;
		c = sqrt(5);
	}
	RectangularTrapezoid(double a, double b, double d,double third_angle,std::string color)
		:Trapeze(a,b,d,90,90,third_angle,color){	}
	~RectangularTrapezoid(){}
};

//---------------------------------------



int main()
{
	/*std::list<Shape*> list1 = {
		new Triangle()
	};
	Triangle trian;
	list1.push_back(&trian);*/
	

}