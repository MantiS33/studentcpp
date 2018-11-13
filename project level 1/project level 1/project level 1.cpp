#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

float check1()
{
	float num;
	while (!(cin>>num))
	{
		cout << "попробуйте снова:";
		cin.clear();
		cin.sync();
		cin.get();
	}
	return num;
}

void calculate2(float Number1, float Number2)
{
	int Choose;
	cout << "Выбирите действие:\n"
		<< "1)+\n"
		<< "2)-\n"
		<< "3)*\n"
		<< "4)/\n";
	cin >> Choose;
	switch (Choose)
	{
	case 1:
	{
		cout << "Результат: " << Number1 + Number2 << endl;
		break;
	}
	case 2: 
	{
		cout << "Результат: " << Number1 - Number2 << endl;
		break;
	}
	case 3:
	{
		cout << "Результат: " << Number1 * Number2 << endl;
		break;
	}
	case 4:
	{
		cout << "Результат: " << Number1 / Number2 << endl;
		break;
	}
	}
	cout << "вы хотите продолжить?  y[да]/n[нет]: ";
}

void calculate(float Number1, float Number2)
{
	float o;
	int action;
	cout << "Выбирите действие:\n" 
		 << "1)+\n" 
		 << "2)-\n" 
		 << "3)*\n" 
		 << "4)/\n" 
		 << "5)Возвидение в квадрат\n" 
		 << "6)извлечение квадратного корня\n"
		 <<"7)Вычиление логарифма\n";
	cin >> action;
	switch (action) 
	{
	case 1: 
	{
		cout << "результат: " << Number1 + Number2 << endl;
		break;
	}
	case 2: 
	{
		cout << "результат: " << Number1 - Number2 << endl;
		break;
	}
	case 3: 
	{
		cout << "результат: " << Number1 * Number2 << endl;
		break;
	}
	case 4:
	{
		cout << "результат: " << Number1 / Number2 << endl;
		break;
	}
	case 5: 
	{
		cout << "квадрат первого числа: " << Number1 * Number1 << endl;
		cout << "квадрат второгго числа: " << Number2 * Number2 << endl;
		break;
	}
	case 6:
	{
		cout << "Корень из первого числа: " << sqrt(Number1) << endl;
		cout << "Корень из второго числа: " << sqrt(Number2) << endl;
		break;
	}
	case 7: 
	{
		cout << "Выбирете основание: ";
		o = check1();
		cout << "логарифм первого числа: " << log(Number1) / log(o) << endl << "логарифм второго числа: " << log(Number2) / log(o) << endl;
		break;
	}
	}
	cout << "вы хотите продолжить?  y[да]/n[нет]: ";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Привет пользователь\n";
	float Number1, Number2;
	char chooseConst='y';
	do
	{
		switch (chooseConst)
		{
		case 'y':
		{
			cout << "Ввидите первое число: ";
			Number1 = check1();
			cout << "Ввидите второе число: ";
			Number2 = check1();
			float temp=abs(Number1)-abs(floor(Number1)), temp2=abs(Number2)-abs(floor(Number2));
			if ((temp < 1 && temp > 0) || (temp2 < 1 && temp2 > 0))
			{
				calculate2(Number1, Number2);
			}
			if (temp==0 && temp2==0)
			{
				calculate(Number1, Number2);
			}
			break;
		}
		case 'n':
		{
			break;
		}
		}
			while (!(cin >> chooseConst))
			{
				cout << "попробуйте снова:";
				cin.clear();
				cin.sync();
				cin.get();
			}
	}
	while (chooseConst == 'y');
	system("pause");
	return 0;
}