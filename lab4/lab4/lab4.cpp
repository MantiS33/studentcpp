#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

struct aeroflot
{
	char* point_of_arrival;
	int flight_number;
	char* airplane;
};

void input(aeroflot* mas, int& size)
{
	char choose = 'y';
	char* buffer = new char[128];
	for (int i = 0; i < size; i++)
	{
		cout << "enter destination name: ";
		cin >> buffer;
		mas[i].point_of_arrival = new char[strlen(buffer) + 1];
		memcpy(mas[i].point_of_arrival, buffer, strlen(buffer) + 1);
		cout << "enter flight number: ";
		cin >> mas[i].flight_number;
		cout << "enter airplane type: ";
		cin >> buffer;
		mas[i].airplane = new char[strlen(buffer) + 1];
		memcpy(mas[i].airplane, buffer, strlen(buffer) + 1);
		if (i != size - 1)
		{
			cout << "do you wanna continue? ";
			cin >> choose;
			cout << endl;
			if (choose != 'y')
			{
				size = i + 1;
				break;
			}
		}
	}
	delete[] buffer;
}

void sort(aeroflot* mas, int& size)
{
	for (int i = 0; i < size - 1; i++)
	{
		aeroflot temp;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (mas[j].flight_number > mas[j + 1].flight_number)
			{
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}

}

void info(aeroflot* mas, int& size)
{
	char buffer[128];
	bool test = false;
	cout << "Enter point of arrival: ";
	cin >> buffer;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(buffer, mas[i].point_of_arrival))
		{
			test = true;
			cout << "type of airplane: " << mas[i].airplane << endl;
			cout << "Flight number: " << mas[i].flight_number << endl;
		}
		cout << endl;
	}
	if (test == false)
	{
		cout << "No flights departing. " << endl;
	}
}

int main()
{
	int size = 7;
	aeroflot* arr = new aeroflot[size];
	input(arr, size);
	sort(arr, size);
	/*for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << arr[i].point_of_arrival << endl;
		cout << arr[i].flight_number << endl;
		cout << arr[i].airplane << endl;
	}*/
	cout << endl;
	char choose;
	cout << "Do you wanna know flight information? ";
	cin >> choose;
	if (choose == 'y')
	{
		info(arr, size);
	}
	for (int i = 0; i < size; i++)
	{
		delete[] arr[i].point_of_arrival;
		delete[] arr[i].airplane;
	}
	delete[] arr;
	system("pause");
	return 0;
}