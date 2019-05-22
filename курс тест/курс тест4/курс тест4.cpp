#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
using namespace std;

class fileinfo
{
private:
	int day, month, year, hour, minute;
public:
	fileinfo():day(0),month(0),year(0),hour(0),minute(0) {}
	fileinfo(int Day,int Month,int Year,int Hour,int Minute):day(Day),month(Month),year(Year),hour(Hour),minute(Minute) {}	
	bool operator<=(const fileinfo& x)
	{
		return (this->day <= x.day) && (this->month <= x.month) && (this->year <= x.year) && (this->hour <= x.hour) && (this->minute <= x.minute);
	}
	bool operator !=(const fileinfo & y)
	{
		return (!(this->day == y.day)) && (!(this->month == y.month)) && (!(this->year == y.year)) && (!(this->hour == y.hour)) && (!(this->minute == y.minute));
	}
	friend ostream& operator<<(ostream& out,const fileinfo& date)
	{
		out << date.day << "." << date.month << "." << date.year << "  " << date.hour << ":" << date.minute;
		return out;
	}
};

template<class Tkey, class Tvalue>
class list
{
private:
	struct element
	{
		Tkey data;
		Tvalue data1;
		int count=0;
		element* next;
	};
	element* head, * tail, * temp;
	void add()
	{
		if (head != NULL)
		{
			tail->next = temp;
			tail = temp;
		}
		else
		{
			head = tail = temp;
		}
	}
public:
	list() :head(NULL), tail(NULL), temp(NULL) {}
	~list()
	{
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}
	bool unique()
	{
		element* Temp = head;
		while (Temp != NULL)
		{
			if (Temp->data == temp->data)
				return false;
			Temp = Temp->next;
		}
		return true;
	}
	Tvalue& operator[](Tkey key)
	{
		this->temp = this->head;
		while (this->temp != NULL)
		{
			if (this->temp->data == key)
			{
				this->temp->count += 1;
				return this->temp->data1;
			}
			this->temp = this->temp->next;
		}
		throw;
	}
	friend ostream& operator<<(ostream & out, list & elem)
	{
		elem.temp = elem.head;
		while (elem.temp != NULL)
		{
			out << elem.temp->data << " : " << elem.temp->data1 << "  " <<elem.temp->count << "\n";
			elem.temp = elem.temp->next;
		}
		return out;
	}
	friend istream& operator>>(istream & in, list & elem)
	{
		elem.temp = new element;
		elem.temp->next = NULL;
		in >> elem.temp->data;
		while (elem.unique() == false)
		{
			in.clear();
			cout << "uncorrectable key!" << endl << "input new: ";
			in >> elem.temp->data;
		}
		in >> elem.temp->data1;
		elem.add();
		return in;
	}
	void Delete(Tvalue num)
	{
		bool test = false;
		temp = head;
		while (temp != NULL)
		{
			if (temp->data1 <= num)
			{
				if (temp == head)
				{
					head = head->next;
					delete temp;
					test = true;
					break;
				}
				if (temp == tail)
				{
					temp = head;
					while (temp->next != tail)
					{
						temp = temp->next;
					}
					delete tail;
					temp->next = NULL;
					tail = temp;
					test = true;
					break;
				}
				if (temp != head && temp != tail)
				{
					temp = head;
					while (temp->next->data1 != num)
					{
						temp = temp->next;
					}
					element* Temp = temp->next;
					temp->next = temp->next->next;
					delete Temp;
					test = false;
					break;
				}
			}
			temp = temp->next;
		}
		if (test == true)
		{
			Delete(num);
		}
		else
		{
			return;
		}
	}
	void add(Tkey key, Tvalue item)
	{
		temp = new element;
		temp->next = NULL;
		temp->data = key;
		while (unique() == false)
		{
			cout << "uncorrectable key!" << endl << "input new: ";
			cin >> temp->data;
		}
		temp->data1 = item;
		add();
	}
};

char Interpreter(string &str)
{
	if (str == "menu")
	{
		return '1';
	}
	if (str == "dir")
	{
		return '2';
	}
	if (str == "create")
	{
		return '3';
	}
	if (str == "delete")
	{
		return '4';
	}
	if (str == "show")
	{
		return '5';
	}
	if (str == "createf")
	{
		return '6';
	}
	if (str == "end")
	{
		return '0';
	}
	return 'e';
}

int main()
{
	string file;
	list<string, fileinfo> a;
	string Choise;
	cout << "V:\\virtual>";
	cin >> Choise;
	cout << endl;
	char choise;
	choise = Interpreter(Choise);
	while (choise)
	{
		switch (choise)
		{
		case '1':
		{
			cout <<endl<< "menu: show menu" << endl 
				<< "dir: show all file" << endl
				<< "create: create a file" << endl 
				<< "createf: create a folder " << endl
				<< "show: show certain file"<<endl
				<< "delete: delete certain file" << endl
				<< "end: close the programm" << endl<<endl;
			break;
		}
		case '2':
		{
			cout << a;
			break;
		}
		case '3':
		{
			cout << "input name: ";
			cin >> file;
			SYSTEMTIME st;
			GetLocalTime(&st);
			a.add(file, fileinfo(st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute));
			break;
		}
		case '4':
		{
			int day, month, year, hour, minute;
			cin >> day;
			cin >> month;
			cin >> year;
			cin >> hour;
			cin >> minute;
			a.Delete(fileinfo(day, month, year, hour, minute));
			break;
		}
		case '5':
		{
			cout << "input a name of file: ";
			cin >> file;
			cout << file << " : " << a[file];
			break;
		}
		case '6':
			cout << "not ready" << endl;
			break;
		case 'e':
		{
			cout <<endl<< "error! try again" << endl<<endl;
			break;
		}
		case '0':
			return 0;
		}
		cout << endl << "V:\\virtual>";
		cin >> Choise;
		cout << endl;
		choise = Interpreter(Choise);
	}
	return 0;
}