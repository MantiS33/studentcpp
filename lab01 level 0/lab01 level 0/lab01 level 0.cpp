#include "pch.h"
#include<iostream>
using namespace std;

void number()
{
	float num = 0;
	int i = 0;
	while (num != 64)
	{
		i += 1;
		cout << i << " try: ";
		cin >> num;
		if (num > 64)
		{
			cout << "\nAnswer: No. Less." << endl;
		}
		if (num < 64)
		{
			cout << "\nAnswer: No. Greater." << endl;
		}
		if (num == 64)
		{
			cout << "\nAnswer: Yes, well done." << endl;
		}
	}
}

void Text()
{
	char name[25];
	int Date, Month, Year, temp;
	cout << "What is your name? ";
	cin >> name;
	cout << name;
	cout << "\nWhen were you born date? ";
	cin >> Date;
	cout << "\nNow month of your birthday ";
	cin >> Month;
	cout << "\nand finally year of your birthday ";
	cin >> Year;
	temp = Date + Month * 30 + Year * 365;
	temp = (736906 - temp) / 365;
	cout << "Hello, " << name << ". You're " << temp << " years old" << endl;
}

void Calculator()
{
	float Number1 = 0, Number2 = 0;
	int Choose = 0;
	cout << "Number 1: ";
	cin >> Number1;
	cout << endl << "Number 2: ";
	cin >> Number2;
	cout << "What do you wanna do?" << endl
		<< "1) +" << endl
		<< "2) -" << endl
		<< "3) *" << endl
		<< "4) /" << endl;
	cout << "Your answer: ";
	cin >> Choose;
	switch (Choose)
	{
	case 1:
	{
		cout << "Result:" << Number1 + Number2 << endl;
		break;
	}
	case 2:
	{
		cout << "Result:" << Number1 - Number2 << endl;
		break;
	}
	case 3:
	{
		cout << "Result:" << Number1 * Number2 << endl;
		break;
	}
	case 4:
	{
		cout << "Result:" << Number1 / Number2 << endl;
		break;
	}
	}
	cout << "Do you wanna try again?	 y/n	";
}

int main()
{
	char ChooseR;
	cout << "Hello, stranger.\nThis is your first program, call me \"Laboratory 1 \ Task 1\".\nYours, C++.\n";
	Text();
	cout << "Hi. Try to guess a number." << endl;
	number();
	cout << "Hello, my dear. What are the numbers?" << endl;
	Calculator();
	cin >> ChooseR;
		switch (ChooseR)
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
	system("pause");
	return 0;
}