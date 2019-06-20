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
	friend ostream& operator<<(ostream& out, const vector& v)
	{
		out << "(" << v.x << ";" << v.y << ")";
		return out;
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

int main()
{
	list<int, char> a;
	list<string, vector> b;
	char choise;
	cout << "1)int and char" << endl << "2)vector" << endl << "0)close" << endl << ">";
	cin >> choise;
	while (choise)
	{
		switch (choise)
		{
		case'1':
		{
			cout << "1)add element " << endl
				<< "2)show all" << endl
				<< "3)show specific item" << endl
				<< "4)delete item" << endl
				<< "0)close" << endl
				<< ">";
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
				case'3':
				{
					int i;
					cout << "input key: ";
					cin >> i;
					cout << i << " : " << a[i] << endl;
					break;
				}
				case '4':
				{
					int num;
					cout << "input key: ";
					cin >> num;
					a.delete_key(num);
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
			cout << "1)add element " << endl 
				<< "2)show all" << endl
				<< "3)show specific item" << endl
				<< "4)delete item" << endl
				<< "0)close" << endl
				<< ">";
			cin >> choise;
			while (choise != '0')
			{
				switch (choise)
				{
				case '1':
				{
					string str;
					cin >> str; 
					int num, num1;
					cin >> num;
					cin >> num1;
					b.add(str, vector(num, num1));
					break;
				}
				case '2':
				{
					cout << b;
					break;
				}
				case'3':
				{
					string i;
					cout << "input key: ";
					cin >> i;
					cout << i << " : " << b[i] << endl;
					break;
				}
				case '4':
				{
					string i;
					cout << "input key: ";
					cin >> i;
					b.delete_key(i);
					break;
				}
				}
				cout << ">";
				cin >> choise;
			}
			b.~list();
			break;
		}
		case '0':
			return 0;
		}
		cout << ">";
		cin >> choise;
	}
	return 0;
}