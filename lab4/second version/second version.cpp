﻿#include <iostream>
#include <string>
using namespace std;

struct aeroflot
{
	char* point_of_arrival;
	int flight_number;
	char* airplane;
	aeroflot* next;
	aeroflot* prev;
};


class list
{
	aeroflot* head, * tail;
public:
	list() :head(NULL), tail(NULL) {};
	~list()
	{
		aeroflot* temp;
		while (head)
		{
			temp = head;
			tail = head->next;
			delete[] temp->point_of_arrival;
			delete[] temp->airplane;
			delete head;
			head = tail;
		}
	}
	void info();
	void sort();
	void add();
};

void list::info()
{
	char buffer[128];
	bool test = false;
	cout << "enter point of arrival: ";
	cin >> buffer;
	cout << endl;
	aeroflot* temp = head;
	while (temp != NULL)
	{
		if (!strcmp(buffer, temp->point_of_arrival))
		{
			test = true;
			cout << "flightnumber: " << temp->flight_number << endl;
			cout << "airplane: " << temp->airplane << endl;
		}
		if (test == false)
		{
			cout << "No flights departing. " << endl;
		}
		temp = temp->next;
	}
	cout << endl;
}

void list::add()
{
	char* buffer = new char[128];
	aeroflot* temp = new aeroflot;
	temp->next = NULL;
	cout << "enter destination name: ";
	cin >> buffer;
	temp->point_of_arrival = new char[strlen(buffer) + 1];
	memcpy(temp->point_of_arrival, buffer, strlen(buffer) + 1);
	cout << "enter flight number: ";
	cin >> temp->flight_number;
	cout << "enter airplane type: ";
	cin >> buffer;
	temp->airplane = new char[strlen(buffer) + 1];
	memcpy(temp->airplane, buffer, strlen(buffer) + 1);
	if (head != NULL)
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	else
	{
		temp->prev = NULL;
		head = tail = temp;
	}
	delete[] buffer;
	sort();
}

void list::sort()
{
	aeroflot* cur = head;
	while (cur->next)
	{
		if ((cur->flight_number) > (cur->next->flight_number))
		{

			int temp = cur->next->flight_number;
			cur->next->flight_number = cur->flight_number;
			cur->flight_number = temp;
			cur = cur->next;
			sort();
		}
		else
		{
			cur = cur->next;
		}
	}
}

/*void list::show()
{
	aeroflot* temp = head;
	while (temp != NULL)
	{
		cout << "point of arrival: " << temp->point_of_arrival << endl;
		cout << "flightnumber: " << temp->flight_number << endl;
		cout << "airplane: " << temp->airplane << endl;
		temp = temp->next;
	}
	cout << endl;
}*/

/*void list::add()
{
	char* buffer = new char[128];
	aeroflot* temp = new aeroflot;
	temp->next = NULL;
	cout << "enter destination name: ";
	cin >> buffer;
	temp->point_of_arrival = new char[strlen(buffer) + 1];
	memcpy(temp->point_of_arrival, buffer, strlen(buffer) + 1);
	cout << "enter flight number: ";
	cin >> temp->flight_number;
	cout << "enter airplane type: ";
	cin >> buffer;
	temp->airplane = new char[strlen(buffer) + 1];
	memcpy(temp->airplane, buffer, strlen(buffer) + 1);
	if (head != NULL)
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	else
	{
		temp->prev = NULL;
		head = tail = temp;
	}

	delete[] buffer;
}*/

int main()
{
	list fly;
	char choose = 'y';
	while (choose == 'y')
	{

		fly.add();
		cout << endl << "do you wanna continue? ";
		cin >> choose;
		cout << endl;
	}
	cout << "Do you wanna know flight information? ";
	cin >> choose;
	if (choose == 'y')
	{
		fly.info();
	}

	system("pause");
	return 0;
}