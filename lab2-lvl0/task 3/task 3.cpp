#include "pch.h"
#include <iostream>
using namespace std;

bool isExceeded(int numToCalculateFactorial, int& stepNumber)
{
	int CompareNum, numFac = 1;
	bool  l = false;
	cout << "Number to compare: ";
	cin >> CompareNum;
	for (int i = 1; i <= numToCalculateFactorial; i++)
	{
		numFac = numFac * i;
		if (numFac >= CompareNum)
		{
			l = true;
			stepNumber = i-1;
			break;
		}
	}
	return l;
}

int main()
{
	int stepNumber, numToCalculateFactorial;
	cout << "Type the number to calculate factorial: ";
	cin >> numToCalculateFactorial;
	bool l = isExceeded(numToCalculateFactorial, stepNumber);
	if (l  == true)
	{
		cout << "Did the factorial exceed the value? YES" << endl << "The step number is " << stepNumber << endl;
	}
	else
	{
		cout << "Did the factorial exceed the value? No" << endl;
	}
	system("pause");
	return 0;
}