#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class time//специальный класс для получения времени
{
protected:
	unsigned int day, month, year, hour, minute;
public:
	time()
	{
		SYSTEMTIME st;
		GetLocalTime(&st);
		this->day = st.wDay;
		this->month = st.wMonth;
		this->year = st.wYear;
		this->hour = st.wHour;
		this->minute = st.wMinute;
	}
	time(int Day, int Month, int Year, int Hour, int Minute) :day(Day), month(Month), year(Year), hour(Hour), minute(Minute) {}
	bool operator<=(const time& x)
	{
		return (this->day <= x.day) && (this->month <= x.month) && (this->year <= x.year) && (this->hour <= x.hour) && (this->minute <= x.minute);
	}
	bool operator !=(const time& y)
	{
		return (!(this->day == y.day)) && (!(this->month == y.month)) && (!(this->year == y.year)) && (!(this->hour == y.hour)) && (!(this->minute == y.minute));
	}
	friend ostream& operator<<(ostream& out, const time& date)
	{
		out << date.day << "." << date.month << "." << date.year << "  " << date.hour << ":" << date.minute;
		return out;
	}
};

class timecount :public time
{
private:
	int count;
public:
	timecount() :count(0), time::time() {}
	timecount(int day, int month, int year, int hour, int minute) : time::time(day, month, year, hour, minute) {}
	friend ostream& operator<<(ostream& out, const timecount& date)
	{
		out << date.day << '.' << date.month << '.' << date.year << "  " << date.hour << ':' << date.minute << "  " << date.count;
		return out;
	}
	void increase()
	{
		this->count = this->count + 1;
	}
};

template<class Tkey, class Tvalue>
class list
{
protected:
	struct element
	{
		Tkey data;
		Tvalue data1;
		element* next;
	};
	element* head, * tail, * temp;
	void add(element* elem)
	{
		if (head != NULL)
		{
			tail->next = elem;
			tail = elem;
		}
		else
		{
			head = tail = elem;
		}
	}
	bool isUnique(Tkey& elem)
	{
		element* Temp = head;
		while (Temp != NULL)
		{
			if (Temp->data == elem)
				return false;
			Temp = Temp->next;
		}
		return true;
	}
public:
	list() :head(NULL), tail(NULL), temp(NULL) {}
	list(list& copy)
	{
		copy.temp = copy.head;
		while (copy.temp != NULL)
		{
			this->add(copy.temp);
			copy.temp = copy.temp->next;
		}
	}
	~list()
	{
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}
	Tvalue& operator[](Tkey key)
	{
		this->temp = this->head;
		while (this->temp != NULL)
		{
			if (this->temp->data == key)
			{
				return this->temp->data1;
			}
			this->temp = this->temp->next;
		}
		throw;
	}
	friend ostream& operator<<(ostream& out, list& elem)
	{
		elem.temp = elem.head;
		while (elem.temp != NULL)
		{
			out << elem.temp->data << " : " << elem.temp->data1 << "\n";
			elem.temp = elem.temp->next;
		}
		return out;
	}
	friend istream& operator>>(istream& in, list& elem)
	{
		elem.temp = new element;
		elem.temp->next = NULL;
		in >> elem.temp->data;
		while (elem.isUnique(elem.temp->data) == false)
		{
			in.clear();
			cout << "uncorrectable key!" << endl << "input new: ";
			in >> elem.temp->data;
		}
		in >> elem.temp->data1;
		elem.add(elem.temp);
		return in;
	}
	void delete_key(Tkey num)
	{
		temp = head;
		while (temp != NULL)
		{
			if (temp->data == num)
			{
				if (temp == head)
				{
					head = head->next;
					delete temp;
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
					break;
				}
				if (temp != head && temp != tail)
				{
					temp = head;
					while (temp->next->data != num)
					{
						temp = temp->next;
					}
					element* Temp = temp->next;
					temp->next = temp->next->next;
					delete Temp;
					break;
				}
			}
			temp = temp->next;
		}
	}
	void delete_value(Tvalue num)
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
			delete_value(num);
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
		while (isUnique(temp->data) == false)
		{
			cout << "uncorrectable key!" << endl << "input new: ";
			cin >> temp->data;
		}
		temp->data1 = item;
		add(temp);
	}
};

class file :public list<string, timecount>
{
private:
	list<string, string> entnairs;
public:
	file() {}
	file(string name)
	{
		list<string, timecount>::add(name, timecount());
		entnairs.add(name, " ");
	}
	void create(string name)
	{
		list<string, timecount>::add(name, timecount());
		entnairs.add(name, " ");
	}
	void write(string name, string str)
	{
		entnairs[name] = str;
		list<string, timecount>::operator[](name).increase();

	}
	void show(string name)
	{
		cout << entnairs[name];
		list<string, timecount>::operator[](name).increase();
	}
};

class folder :public list<string, time>//класс папка, для хоанения указателя на след. скласс(также выполняющий функ-цию компоновщика, наверное) 
{
private:
	list<string, folder*> pointer;
	file files;
public:
	folder() {}
	void adding(string name, folder* point)
	{
		pointer.add(name, point);
		list<string, time>::add(name, time());
	}
	void create(string name)
	{
		files.create(name);
	}
	void _delete(int day, int month, int year, int hour, int minute)
	{
		files.delete_value(timecount(day, month, year, hour, minute));
	}
	void show(string name)
	{
		files.show(name);
	}
	void write(string name, string str)
	{
		files.write(name, str);
	}
	void dir()
	{
		cout << *this << files;
	}
	folder* getAddres(string name)
	{
		return pointer[name];
	}
};

char Interpreter(string& str)
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
	if (str == "openf")
	{
		return '7';
	}
	if (str == "write")
	{
		return '8';
	}
	if (str == "end")
	{
		return '0';
	}
	return 'e';
}

void MENU()
{
	cout << endl << "menu: show menu" << endl
		<< "dir: show all file" << endl
		<< "create: create a file" << endl
		<< "createf: create a folder " << endl
		<< "show: open the file to read " << endl
		<< "delete: delete certain file" << endl
		<< "openf: open a folder" << endl
		<< "write: write down info in file" << endl
		<< "end: close the programm" << endl << endl;
}

void test_n_file(string& str)
{
	string::size_type n = str.find(".txt");
	while (n == string::npos)
	{
		cout << "this is not a file. try again: ";
		cin >> str;
		n = str.find(".txt");
	}
}

void test_n_folder(string& str)
{
	string::size_type n = str.find(".txt");
	while (n != string::npos)
	{
		cout << "this is not a folder. try again: ";
		cin >> str;
		n = str.find(".txt");
	}
}

void openf(string str, folder* elem)
{
	string choose, catalog;
	char choice;
	catalog = str;
	cout << catalog << ">";
	cin >> choose;
	choice = Interpreter(choose);
	while (choice)
	{
		switch (choice)
		{
		case '1':
		{
			MENU();
			break;
		}
		case '2':
		{
			cout << endl;
			elem->dir();
			break;
		}
		case '3':
		{
			string name;
			cout << endl << "input name of file: ";
			cin >> name;
			test_n_file(name);
			elem->create(name);
			break;
		}
		case '4':
		{
			cout << endl << "input date as day.month.year hour:minute  : ";
			int day, month, year, hour, minute;
			cin >> day;
			cin >> month;
			cin >> year;
			cin >> hour;
			cin >> minute;
			elem->_delete(day, month, year, hour, minute);
			break;
		}
		case '5':
		{
			cout << endl;
			string name;
			cout << "input name of file:";
			test_n_file(name);
			elem->show(name);
			break;
		}
		case '6':
		{
			string Folder;
			cout << endl << "input name of folder: ";
			cin >> Folder;
			test_n_folder(Folder);
			elem->adding(Folder, new folder);
			break;
		}
		case '7':
		{
			string Folder;
			cout << endl << "input name of folder: ";
			cin >> Folder;
			test_n_folder(Folder);
			openf(catalog + "\\" + Folder, elem->getAddres(Folder));
			break;
		}
		case '8':
		{
			string name;
			string str;
			cout << "input name of file:";
			cin >> name;
			test_n_file(name);
			cout << "input what you wanna write down:";
			cin.get();
			getline(cin, str);
			elem->write(name, str);
			break;
		}
		case 'e':
		{
			cout << endl << "error! try again" << endl;
			break;
		}
		case '0':
		{
			return;
		}
		}
		cout << endl << catalog << ">";
		cin >> choose;
		choice = Interpreter(choose);
	}
}

int main()
{
	MENU();
	folder Virtual;
	Virtual.adding("virtual", new folder);
	openf("V:\\virtual", Virtual.getAddres("virtual"));
	return 0;
}