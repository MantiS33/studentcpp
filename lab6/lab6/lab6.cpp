#include <iostream>
using namespace std;

class vector
{
private:
	float X, Y;
public:
	vector() : X(0), Y(0) {}
	vector(float x, float y) : X(x), Y(y) {}
	vector(const vector& elem)
	{
		X = elem.X;
		Y = elem.Y;
	}
	friend ostream& operator<<(ostream& out, const vector& elem)
	{
		out << "(" << elem.X << ":" << elem.Y << ")";
		return out;
	}
	friend istream& operator>>(istream& in, vector& elem)
	{
		in >> elem.X;
		in >> elem.Y;
		return in;
	}
	vector operator+(vector& elem)
	{
		return vector((elem.X + this->X), (elem.Y + this->Y));
	}
	vector operator-(vector & elem)
	{
		return vector((this->X - elem.X), (this->Y - elem.Y));
	}
	vector & operator=(const vector & elem)
	{
		if (this == &elem)
			return *this;
		this->X = elem.X;
		this->Y = elem.Y;
		return *this;
	}
	double operator*(const vector & elem)
	{
		return (this->X * elem.X + this->Y * elem.Y);
	}
	double lenght()
	{
		return (sqrt((this->X * this->X) + (this->Y * this->Y)));
	}
};

void MENU()
{
	cout << "1)ввести координаты векторов" << endl
		<< "2)вывести координаты векторов" << endl
		<< "3)сложить два вектора" << endl
		<< "4)вычесть два вектора" << endl
		<< "5)скалярное произведение двух векторов" << endl
		<< "6)длина вектора" << endl
		<< "0)закрыть программу" << endl
		<< "!)вывести меню" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	vector v[2];
	char choise;
	MENU();
	cout << '>';
	cin >> choise;
	while (choise)
	{
		switch (choise)
		{
		case '1':
		{
			cout << "введите координаты первого вектора: ";
			cin >> v[0];
			cout << "ввидите координаты второго вектора: ";
			cin >> v[1];
			break;
		}
		case '2':
		{
			cout << v[0] << endl << v[1] << endl;
			break;
		}
		case '3':
		{
			cout << v[0] + v[1] << endl;
			break;
		}
		case '4':
		{
			int i;
			cout << "выбирите из какого вектора хотите вычесть, 1 или 2 ? :";
			cin >> i;
			while (i > 2 || i < 1)
			{
				cout << "ошибка ввидите снова: ";
				cin >> i;
			}
			if (i == 1)
			{
				cout << v[0] - v[1] << endl;
			}
			else
			{
				cout << v[1] - v[0] << endl;
			}
			break;
		}
		case '5':
		{
			cout << "скалярное произведение = " << v[0] * v[1] << endl;
			break;
		}
		case '6':
		{
			int i;
			cout << "длину какого вектора хотите найти: ";
			cin >> i;
			while (i > 2 || i < 1)
			{
				cout << "ошибка ввидите снова: ";
				cin >> i;
			}
			cout << "длина вектора = " << v[i - 1].lenght() << endl;
			break;
		}
		case '!':
		{
			MENU();
			break;
		}
		case '0':
			return 0;
		}
		cout << '>';
		cin >> choise;
	}
	return 0;
}