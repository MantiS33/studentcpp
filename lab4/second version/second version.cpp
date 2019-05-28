#include <iostream>
using namespace std;

struct aeroflot
{
	char* point_of_arrival;
	int flight_number;
	char* airplane;
};

struct list
{
	aeroflot data;
	list* next, * prev;
};

list* head = NULL;
list* tail = NULL;

void add(aeroflot elem)
{
	list* Temp = head;
	list* temp = new list;
	temp->data = elem;
	temp->next = NULL;
	temp->prev = NULL;
	if (head != NULL)
	{
		/*temp->next = head;
		head->prev = temp;
		head = temp;*/
		if (Temp->next != NULL)
		{
			while (Temp != NULL)
			{
				if ((temp->data.flight_number > Temp->data.flight_number) && (temp->data.flight_number < Temp->next->data.flight_number))
				{
					temp->next = Temp->next;
					temp->prev = Temp;
					Temp->next->prev = temp;
					Temp->next = temp;
				}
				if (temp->data.flight_number < head->data.flight_number)
				{
					temp->next = head;
					head->prev = temp;
					head = temp;
					break;
				}
				if (temp->data.flight_number > tail->data.flight_number)
				{
					temp->prev = tail;
					tail->next = temp;
					tail = temp;
					break;
				}
				Temp = Temp->next;
			}
		}
		else
		{
			if (temp->data.flight_number < head->data.flight_number)
			{
				temp->next = head;
				head->prev = temp;
				head = temp;
			}
			if (temp->data.flight_number > tail->data.flight_number)
			{
				temp->prev = tail;
				tail->next = temp;
				tail = temp;
			}
		}
	}
	else
	{
		head = tail = temp;
	}
}

void show()
{
	list* temp = head;
	while (temp != NULL)
	{
		cout << temp->data.point_of_arrival << endl << temp->data.flight_number << endl << temp->data.airplane << endl;
		temp = temp->next;
	}
}

void show(char buffer[], int n)
{
	list* temp = head;
	while (temp != NULL)
	{
		if (!strcmp(buffer, temp->data.point_of_arrival))
		{
			cout << "flightnumber: " << temp->data.flight_number << endl;
			cout << "airplane: " << temp->data.airplane << endl;
			cout << endl;
		}
		temp = temp->next;
	}
}

void clear()
{
	while (head != NULL)
	{
		delete[] head->data.point_of_arrival;
		delete[] head->data.airplane;
		list* temp = head;
		head = head->next;
		delete temp;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	char choise;
	cout << "do you wanna enter the fly information? [y/n] ";
	cin >> choise;
	if (choise == 'y')
	{
		while (choise == 'y')
		{
			cout << endl;
			aeroflot elem;
			char* buff = new char[256];
			cout << "enter destination name: ";
			cin >> buff;
			elem.point_of_arrival = new char[strlen(buff) + 1];
			memcpy(elem.point_of_arrival, buff, strlen(buff) + 1);
			cout << "enter flight number: ";
			cin >> elem.flight_number;
			cout << "enter airplane type: ";
			cin >> buff;
			elem.airplane = new char[strlen(buff) + 1];
			memcpy(elem.airplane, buff, strlen(buff) + 1);
			add(elem);
			cout << endl;
			cout << "do you wanna continue? [y/n] ";
			cin >> choise;
		}
	}
	else
	{
		if (head == NULL)
		{
			clear();
			return 0;
		}
	}
	cout << "do you wanna know a fly information? [y/n] ";
	cin >> choise;
	cout << endl;
	while (choise == 'y')
	{
		char* buff = new char[256];
		cout << "enter distanation name: ";
		cin >> buff;
		show(buff, strlen(buff) + 1);
		cout << "do you wanna know a fly information? [y/n] ";
		cin >> choise;
		cout << endl;
	}
	clear();
	return 0;
}