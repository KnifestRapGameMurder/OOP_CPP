#include<iostream>
#include<algorithm>
#include<cmath>

class Fraction;
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
void reduce();

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	//		Type cost operators:
	explicit operator int()
	{
		return this->integer;
	}


	//		Methods
	int get_integer() const
	{
		return this->integer;
	}
	int get_numerator() const
	{
		return this->numerator;
	}
	int get_denominator() const
	{
		return this->denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator)
		{
			this->denominator = denominator;
		}
		else
		{
			throw std::exception("F#cking F#ck, davay tak ne delat");
		}
	}

	//			Constructors:
	Fraction() :integer(0), numerator(0), denominator(1)
	{
		/*this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;*/
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}
	explicit Fraction(int integer) :integer(integer), numerator(0), denominator(1)
	{
		/*this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;*/
		std::cout << "SingleArgConstructor(int):\t" << this << std::endl;
	}
	Fraction(double number)
	{
		integer = number;
		long double buffer = (number - integer);
		//buffer *= 1000000000;
		//buffer = round(buffer);
		/*int i = 0;
		for (; buffer > (int)buffer; i++)
		{
			buffer *= 10;
		}*/
		numerator = round(buffer * 1000000000);
		denominator = 1000000000;
		//Fraction result = *this;
		reduce();

		/*integer = number;
		number -= integer;

		for (int i = 0; i < 9; i++)
		{
			number *= 10;
			denominator *= 10;
		}
		std::cout << number << std::endl;*/

		std::cout << "SingleArgConstructor(double):\t" << this << std::endl;
	}
	Fraction(int numerator, int denominator) :
		integer(0), numerator(numerator), denominator(denominator ? denominator : 1)
	{
		/*this->integer = 0;
		this->numerator = numerator;
		this->denominator = denominator;*/
		std::cout << "DoubleArgConstructor:\t" << this << std::endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;
		std::cout << "Constructor:\t" << this << std::endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyConstructor:" << this << std::endl;
	}
	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}

	//		Operators:
	//					=	=	=	=	=
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}

	//					++	++	++	++	++
	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction temp = *this;
		this->integer++;
		return temp;
	}

	Fraction operator+(const Fraction other)
	{
		Fraction result;
		result.integer = this->integer + other.integer;
		result.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
		result.denominator = this->denominator * other.denominator;
		result.reduce();
		result.to_proper();
		std::cout << "operator +" << std::endl;
		return result;
	}
	Fraction operator-(const Fraction other)
	{
		Fraction result;
		result.numerator = (this->integer * this->denominator + this->numerator) * other.denominator - (other.integer * other.denominator + other.numerator) * this->denominator;
		result.denominator = this->denominator * other.denominator;
		result.reduce();
		result.to_proper();
		std::cout << "operator -" << std::endl;
		return result;
	}
	/*Fraction operator*(const Fraction other)
	{
	Fraction result;
	result.numerator = (this->integer * this->denominator + this->numerator)*(other.integer*other.denominator + other.numerator);
	result.denominator = this->denominator* other.denominator;
	result.reduce();
	result.to_proper();
	std::cout << "operator *" << std::endl;
	return result;
	}*/
	Fraction operator/(const Fraction other)
	{
		Fraction result;
		result.numerator = (this->integer * this->denominator + this->numerator) * other.denominator;
		result.denominator = this->denominator * (other.integer * other.denominator + other.numerator);
		result.reduce();
		result.to_proper();
		std::cout << "operator /" << std::endl;
		return result;
	}



	void print()
	{
		if (!numerator)
		{
			std::cout << integer << std::endl;
		}
		else if (!integer)
		{
			std::cout << numerator << "/" << denominator << std::endl;
		}
		else
		{
			std::cout << integer << " [" << numerator << "/" << denominator << "]" << std::endl;
		}
	}

	void to_proper()
	{
		if (numerator >= denominator)
		{
			integer += numerator / denominator;
			numerator %= denominator;
		}
	}

	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}

	void reduce()
	{
		/*int larger = std::max(numerator, denominator);
		int fewer = std::min(numerator, denominator);
		int remainder = 0;*/

		int larger, fewer;
		if (numerator > denominator)
		{
			larger = numerator;
			fewer = denominator;
		}
		else
		{
			larger = denominator;
			fewer = numerator;
		}
		int remainder = larger % fewer;

		do
		{
			remainder = larger % fewer;
			larger = fewer;
			fewer = remainder;
		} while (remainder);

		/*if (larger % fewer == 0)
		{
			nod = fewer;
		}

		else if ((fewer % (larger % fewer)) == 0)
		{
			nod = larger % fewer;
		}
		else if (((larger % fewer) % (fewer % (larger % fewer))) == 0)
		{
			nod = fewer % (larger % fewer);
		}
		else
		{
			nod = 1;
		}*/

		int GCD = larger;	//Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
	}

};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
	result.reduce();
	result.to_proper();
	return result;
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();

	//int result = left.get_numerator()*right.get_denominator() / left.get_denominator() / right.get_numerator();
	//(result > 1) ? std::cout << right << ">" << left << std::endl : (result < 1) ? std::cout << right << "<" << left << std::endl : std::cout << left << "=" << right << std::endl;
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();

}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (!obj.get_numerator())
	{
		std::cout << obj.get_integer() << std::endl;
	}
	else if (!obj.get_integer())
	{
		std::cout << obj.get_numerator() << "/" << obj.get_denominator() << std::endl;
	}
	else
	{
		std::cout << obj.get_integer() << " [" << obj.get_numerator() << "/" << obj.get_denominator() << "]" << std::endl;
	}
	return os;
}



//#define CONSTRUCTORS_CHECK
//#define OPERATORS
//#define OPERATORS_CHECK
//#define TYPE_CONVERSION

void main()
{


#ifdef OPERATORS

	Fraction A(1, 4);
	A.print();
	Fraction B(7, 4);
	B.print();
	Fraction C = A * B;
	C.print();
	operator<(A, B);

#endif // OPERATORS


#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	try
	{
		A.set_integer(2);
		A.set_numerator(9);
		A.set_denominator(4);
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;
	}
	A.print();
	A.to_proper();
	A.print();
	A.to_improper();
	A.print();

	Fraction B;
	try
	{
		B.set_integer(2);
		B.set_numerator(3600);
		B.set_denominator(840);
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;
	}
	B.print();
	B.reduce();
	B.print();
	Fraction C;
	C.print();
	Fraction D = C;
	D.print();
	Fraction E = 3;
	E.print();
	Fraction F(1, 2);
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATORS_CHECK

	Fraction A(1, 2);
	Fraction B(4, 9);
	std::cout << (A > B) << std::endl;


#endif // OPERATORS_CHECK

#ifdef TYPE_CONVERSION

	std::cout << (char)43 << std::endl;	//C-like notation
	std::cout << char(44) << std::endl;	//Functional notation
	5.8 + 2 * '+';
	std::cout << typeid('a' - 'A').name() << std::endl;
	std::cout << (double)7 / 2 << std::endl;

	Fraction A = 5;
	std::cout << "\n-------------------------------\n" << std::endl;

	std::cout << "\n-------------------------------\n" << std::endl;
#endif // TYPE_CONVERSION

	//Fraction B;		//Default constructor
	//B = (Fraction)8;
	//std::cout << B << std::endl;
	////////////////////////
	//Fraction C(5, 3, 8);
	//int c = (int)C;
	//std::cout << c << std::endl;
	Fraction A;
	A = 2.23;
	std::cout << A << std::endl;
	std::cout << UINT_MAX << std::endl;

	std::cout << sizeof(long double) << std::endl;

	std::cout << Fraction(0, 0) << std::endl;

	int a = 2;
	int b(3);

}

