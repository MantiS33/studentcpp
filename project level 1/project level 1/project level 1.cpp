#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

float check1()
{
	float num;
	while (!(cin >> num))
	{
		cout << "попробуйте снова:";
		cin.clear();
		cin.sync();
		cin.get();
	}
	return num;
}

void calculate2()
{
	float Number1, Number2;
	int Choose;
	cout << "Ввидите первое число:";
	Number1 = check1();
	cout << "Ввидите второе число:";
	Number2 = check1();
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
		cout << "Результат" << Number1 + Number2 << endl;
		break;
	}
	case 2: 
	{
		cout << "Результат" << Number1 - Number2 << endl;
		break;
	}
	case 3:
	{
		cout << "Результат" << Number1 * Number2 << endl;
		break;
	}
	case 4:
	{
		cout << "Результат" << Number1 / Number2 << endl;
		break;
	}
	}
	cout << "вы хотите продолжить?  y[да]/n[нет]:";
}

void calculate()
{
	int a, b, o;
	int action;
	cout << "Ввидите первое число:";
	while (!(cin >> a)) 
	{
		cout << "попробуйте снова:";
		cin.clear();
		cin.sync();
		cin.get();
	}
	cout << "Ввидите второе число:";
	while (!(cin >> b)) 
	{
		cout << "поробуйте снова:";
		cin.clear();
		cin.sync();
		cin.get();
	}
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
		cout << "результат:" << a + b << endl;
		break;
	}
	case 2: 
	{
		cout << "результат:" << a - b << endl;
		break;
	}
	case 3: 
	{
		cout << "результат:" << a * b << endl;
		break;
	}
	case 4:
	{
		cout << "результат:" << a / b << endl;
		break;
	}
	case 5: 
	{
		cout << "квадрат первого числа:" << a * a << endl;
		cout << "квадрат второгго числа:" << b * b << endl;
		break;
	}
	case 6:
	{
		cout << "Корень из первого числа:" << sqrt(a) << endl;
		cout << "Корень из второго числа:" << sqrt(b) << endl;
		break;
	}
	case 7: 
	{
		cout << "Выбирете основание:";
		cin >> o;
		cout << "логарифм первого числа:" << log(a) / log(o) << endl << "логарифм второго числа:" << log(b) / log(o) << endl;
		break;
	}
	}
	cout << "вы хотите продолжить?  y[да]/n[нет]:";
}

void typeThenum()
{
	int Choose;
	cout << "Вы хотите работать с целыми или с дробными числами:" << endl << "1)целые" << endl << "2)дробные" << endl;
	cin >> Choose;
	switch (Choose)
	{
	case 1:
	{
		calculate();
		break;
	}
	case 2: 
	{
		calculate2();
		break;
	}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Привет пользователь\n";
	typeThenum();
	char chooseConst;
	while (!(cin>>chooseConst)||chooseConst=='y')
	{
		switch (chooseConst) 
		{
		case 'y': 
		{
			typeThenum();
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