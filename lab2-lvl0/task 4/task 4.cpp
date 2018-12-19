#include "pch.h"
#include <iostream>
using namespace std;

bool numTest(int Num, bool& Test2, int& Test3, bool& Test4)
{
	if ((Num % 2) == 0)
	{
		Test2 = true;
	}
	else
	{
		Test2 = false;
	}
	Test3 = Num % 5;
	if (Num > 10)
	{
		Test4 = true;
	}
	else
	{
		Test4 = false;
	}
	if (abs(Num) == Num)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	bool Test2, Test4;
	int Test3, Num;
	cout << "Enter a number: ";
	cin >> Num;
	if (numTest(Num, Test2, Test3, Test4) == true)
	{
		cout << "Positive number" << endl;
		if (Test2 == true)
		{
			cout << "the number is even" << endl;
		}
		else
		{
			cout << "The number is not even" << endl;
		}
		cout << "the remainder of dividing the number by 5  " << Test3 << endl;
		if (Test4 == true)
		{
			cout << "this number is more than 10" << endl;
		}
		else
		{
			cout << "this number is not more than 10" << endl;
		}
	}
	else
	{
		cout << "negative number" << endl;
		if (Test2 == true)
		{
			cout << "the number is even" << endl;
		}
		else
		{
			cout << "The number is not even" << endl;
		}
		cout << "the remainder of dividing the number by 5  " << Test3 << endl;
		if (Test4 == true)
		{
			cout << "this number is more than 10" << endl;
		}
		else
		{
			cout << "this number is not more than 10" << endl;
		}
	}
	system("pause");
	return 0;
}