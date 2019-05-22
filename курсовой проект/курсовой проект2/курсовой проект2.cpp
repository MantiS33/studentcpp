#include <iostream>
#include <string>
using namespace std;

class vector
{
private:
	int x, y;
public:
	vector() : x(0), y(0) {}
	vector(int X, int Y) : x(X), y(Y) {}
	friend ostream& operator<<(ostream& out, vector& v)
	{
		out << "(" << v.x << ";" << v.y << ")";
		return out;
	}
};

class test
{
private:
	int num;
	string str;
public:
	test() :num(0), str("nope") {}
	//test(int num, string str) :num(num), str(str) {}
	friend ostream& operator<<(ostream& out, const test& elem)
	{
		out << elem.num << " : " << elem.str;
		return out;
	}
	friend istream& operator>>(istream& in, test& elem)
	{
		in >> elem.num;
		elem.add();
		return in;
	}
	void add()
	{
		char* buff = new char[256];
		cin.getline(buff, 256);
		str = buff;
		delete[] buff;
	}
	/*friend istream& operator>>(istream& in, test& elem)
	{
		in >> elem.num;
		in >> elem.str;
		return in;
	}*/
};



template <class T>
class list
{
private:
	struct element
	{
		T data;
		element* next;
	};
	element* head, * tail;
	element* temp;
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

	friend ostream& operator <<(ostream& out, list& elem)
	{
		elem.temp = elem.head;
		while (elem.temp != NULL)
		{
			out << elem.temp->data << "\n";
			elem.temp = elem.temp->next;
		}
		return out;
	}
	friend istream& operator>>(istream& in, list& elem)
	{
		elem.temp = new element;
		elem.temp->next = NULL;
		in >> elem.temp->data;
		if (elem.head != NULL)
		{
			elem.tail->next = elem.temp;
			elem.tail = elem.temp;
		}
		else
		{
			elem.head = elem.tail = elem.temp;
		}
		return in;
	}
	void add(T elem);
	/*void output();
	T& Get()
	{
		return Temp->data;
	}*/
};

template <class T>
void list<T>::add(T elem)
{
	temp = new element;
	temp->data = elem;
	temp->next = NULL;
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

/*template<class T>
void list<T>::output()
{
	Temp = head;
	while (Temp != NULL)
	{
		cout << Get() << endl;
		Temp = Temp->next;
	}
}*/

int main()
{
	setlocale(LC_ALL, "rus");
	list<test> a;
	list<int> b;
	list<vector> c;
	char choise, choisemain;
	cout << "1)пользовательский тип данных" << endl
		<< "2)тип данных int" << endl
		<< "3)тип вектор" << endl
		<< "0)закрыть" << endl
		<< ">";
	cin >> choisemain;
	while (choisemain)
	{
		switch (choisemain)
		{
		case '1':
		{
			cout << "1)добавить элемент" << endl << "2)вывести информацию" << endl << "0)закрыть" << endl << ">";
			cin >> choise;
			while (choise != '0')
			{
				switch (choise)
				{
				case '1':
				{
					cin >> a;
					break;
				}
				case '2':
				{
					cout << a;
					break;
				}
				}
				cout << ">";
				cin >> choise;
			}
			a.~list();
			break;
		}
		case '2':
		{
			cout << "1)добавить элемент" << endl << "2)вывести информацию" << endl << "0)закрыть" << endl << ">";
			cin >> choise;
			while (choise != '0')
			{
				switch (choise)
				{
				case '1':
				{
					cin >> b;
					break;
				}
				case '2':
				{
					cout << b;
					break;
				}
				}
				cout << ">";
				cin >> choise;
			}
			b.~list();
			break;
		}
		case '3':
		{
			cout << "1)добавить элемент" << endl << "2)вывести информацию" << endl << "0)закрыть" << endl << ">";
			cin >> choise;
			while (choise != '0')
			{
				switch (choise)
				{
				case '1':
				{
					int num, num1;
					cin >> num;
					cin >> num1;
					c.add(vector(num, num1));
					break;
				}
				case '2':
				{
					cout << c;
					break;
				}
				}
				cout << ">";
				cin >> choise;
			}
			c.~list();
			break;
		}
		case '0':
		{
			return 0;
		}
		}
		cout << ">";
		cin >> choisemain;
	}
	return 0;
}