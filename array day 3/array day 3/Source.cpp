#include<iostream>
using namespace std;

//#define MOVE
#define SORTING

void main() {
#ifdef MOVE
	const int SIZE = 10;
	int arr[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int stepz, side;
	int temp = 0;//буферная переменная
	cout << "Starter massive:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "How much steps do you want to make? (MAX is " << SIZE << ") ";
	cin >> stepz;
	cout << "Which side? (0 - right, 1 - left) ";
	cin >> side;
	if (side == 0)
	{
		for (int i = 0; i < stepz; i++)
		{
			temp = arr[SIZE - 1];
			for (int j = 1; j < SIZE; j++)
			{
				arr[SIZE - 1] = arr[SIZE - j - 1];
			}
			arr[0] = temp;
		}
	}
	else {
		for (int i = 0; i < stepz; i++)
		{
			temp = arr[0];
			for (int j = 0; j < SIZE - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			arr[SIZE - 1] = temp;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
#endif // MOVE

#ifdef SORTING
	const int SIZE = 10;
	int arr[SIZE];
	int temp;//буферная переменная
	for (int i = 0; i < SIZE; i++) 
	{
		arr[i] = rand() % 100;
	}
	cout << "Starter massive: " << endl;
	for (int i = 0; i < SIZE; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout <<"The same massive but all numbers are in order from the smallest to the biggest number: "<< endl;
	for (int i = 0; i < SIZE; i++) 
	{
		if (arr[i] > arr[i + 1]) 
		{
			
		}
	}
	for (int i = 0; i < SIZE; i++) 
	{
		cout << arr[i] << " ";
	}
#endif // SORTING

}
