#include "pch.h"
#include <iostream>
using namespace std;

bool numTest(int Num, bool& Test2, int& Test3, bool& Test4)
{
	Test2 = (Num % 2 == 0 ? true : false);
	Test3 = Num % 5;
	Test4 = (Num > 10 ? true : false);
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
	bool Test1,Test2, Test4;
	int Test3, Num;
	cout << "Enter a number: ";
	cin >> Num;
	Test1 = numTest(Num, Test2, Test3, Test4);
	(Test1 == true ? cout << "the number is positiv" << endl : cout << "the number is negative" << endl);
	(Test2 == true ? cout << "the number is even" << endl : cout << "the number is not even" << endl);
	cout << "the remainder of dividing the number by 5  " << Test3 << endl;
	(Test4 == true ? cout << "the number is more then 10" << endl : cout << "the number is less the 10" << endl);
	system("pause");
	return 0;
}