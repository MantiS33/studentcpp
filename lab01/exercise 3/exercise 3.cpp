#include "pch.h"
#include <iostream>
using namespace std;

void Calculator()
{
	int Choose;
	float Number1, Number2;
	cout << "Hello, my dear. What are the numbers?" << endl << "Number 1: ";
	cin >> Number1;
	cout << "Number 2: ";
	cin >> Number2;
	cout << "What do you want to do?\n1. +\n2. -\n3. *\n4. /\nYour answer: ";
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