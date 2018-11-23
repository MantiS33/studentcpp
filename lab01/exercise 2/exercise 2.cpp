#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

void Calculator()
{
	int Number1, Number2, Choose;
	cout << "Hello, my dear. What are the numbers?" << endl << "Number 1: ";
	cin >> Number1;
	cout << "Number 2: ";
	cin >> Number2;
	cout << "What do you want to do?\n1. +\n2. -\n3. *\n4. /\n5. sqr\n6. sqrt\n7. log\nYour answer: ";
	cin >> Choose;
	switch (Choose)
	{
	case 1:
	{
		cout << "Result = " << Number1 + Number2 << endl;
		break;
	}
	case 2:
	{
		cout << "Result = " << Number1 - Number2 << endl;
		break;
	}
	case 3:
	{
		cout << "Result = " << Number1 * Number2 << endl;
		break;
	}
	case 4:
	{
		cout << "Result = " << Number1 / Number2 << endl;
		break;
	}
	case 5:
	{
		cout << "Result for number 1 = " << Number1 * Number1 << endl << "Result for number 2 = " << Number2 * Number2 << endl;
		break;
	}
	case 6:
	{
		cout << "Result for number 1 = " << sqrt(Number1) << endl << "Result for number 2 = " << sqrt(Number2) << endl;
		break;
	}
	case 7:
	{
		int O;
		cout << "base of logarithm: ";
		cin >> O;
		cout << "Result for number 1 = " << log(Number1) / log(O) << endl << "Result for number 2 = " << log(Number2) / log(O) << endl;
		break;
	}
	}
	cout << "Do you want to try again? y/n" << endl;
}

int main()
{
	Calculator();
	char Choose;
	while (!(cin >> Choose) || Choose == 'y')
	{
		switch (Choose)
		{
		case 'y':
		{
			Calculator();
			break;
		}
		case 'n':
		{
			break;
		}
		}
		cin.clear();
		cin.get();
	}
	system("pause");
	return 0;
}