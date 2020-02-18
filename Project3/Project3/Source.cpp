#include <iostream>
using namespace std;


int add(int a, int b)
{
	int result = a + b;
	return result;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

double div_(double a, double b)
{
	return a / b;
}

void main()
{
	int a, b;
	cout << " input 2 number: "; cin >> a >> b;
	int c = add(a, b);
	cout << c << endl;
	cout << sub(a, b) << endl;
	cout << div_(a, b) << endl;
}


























































