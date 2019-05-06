#include <iostream>
using namespace std;

class rectangle
{
private:
	double x1, y1, x2, y2;
public:
	rectangle() :x1(0), y1(0), x2(0), y2(0) {};
	~rectangle()
	{

	}
	void input();
	void output();
	void change_place();
	void change_size();
	void least_rectangle();
	void crossing();
};

double min(double a, double b)
{
	if (a < b)
		return a;
	else
		return b;
}

double max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

void rectangle::crossing()
{
	rectangle* temp = new rectangle[2];
	(temp[0]).x1 = x1;
	(temp[0]).x2 = x2;
	(temp[0]).y1 = y1;
	(temp[0]).y2 = y2;
	cout << "ввидите координаты x левых точек второго прямоугольника: ";
	cin >> (temp[1]).x1;
	cout << "ввидите координаты y верхних точек второго прямоугольника: ";
	cin >> (temp[1]).y1;
	cout << "ввидите координаты x правых точек второго прямоугольника: ";
	cin >> (temp[1]).x2;
	cout << "ввидите координаты y нижних точек второго прямоугольника: ";
	cin >> (temp[1]).y2;
	if ((temp[0]).x1 > (temp[1]).x2 || (temp[0]).x2 < (temp[1]).x1 || (temp[0]).y1<(temp[1]).y2 || (temp[0]).y2>(temp[0]).y1)
	{
		cout << "прямоугольники не пересекаются" << endl;
	}
	else
	{
		cout << "координаты прямоугольника" << endl
			<< "A: (" << max((temp[0]).x1, (temp[1]).x1) << ";" << min((temp[0]).y1, (temp[1]).y1) << ")" << endl
			<< "B: (" << min((temp[0]).x2, (temp[1]).x2) << ";" << min((temp[0]).y1, (temp[1]).y1) << ")" << endl
			<< "C: (" << min((temp[0]).x2, (temp[1]).x2) << ";" << max((temp[0]).y2, (temp[1]).y2) << ")" << endl
			<< "D: (" << max((temp[0]).x1, (temp[1]).x1) << ";" << max((temp[0]).y2, (temp[1]).y2) << ")" << endl;
	}
	delete[] temp;
}

void rectangle::least_rectangle()
{
	rectangle* temp = new rectangle[3];
	(temp[0]).x1 = x1;
	(temp[0]).x2 = x2;
	(temp[0]).y1 = y1;
	(temp[0]).y2 = y2;
	cout << "ввидите координаты x левых точек второго прямоугольника: ";
	cin >> (temp[1]).x1;
	cout << "ввидите координаты y верхних точек второго прямоугольника: ";
	cin >> (temp[1]).y1;
	cout << "ввидите координаты x правых точек второго прямоугольника: ";
	cin >> (temp[1]).x2;
	cout << "ввидите координаты y нижних точек второго прямоугольника: ";
	cin >> (temp[1]).y2;
	if (((temp[0]).x2 - (temp[0]).x1) >= (temp[0].y2 - (temp[0]).y1))
	{
		(temp[2]).x1 = abs((temp[0]).x1);
		(temp[2]).y2 = abs((temp[0]).y2);
		(((temp[1]).x2 - (temp[1]).x1) >= ((temp[1]).y1 - (temp[1]).y2) ? (temp[2].y1 = (temp[0]).y1 + ((temp[1]).y1 - (temp[1]).y2)) : (temp[2].y1 = (temp[0]).y1 + ((temp[1]).x2 - (temp[1]).x1)));
		if (((temp[1]).x2 - (temp[1]).x1) >= ((temp[1]).y1 - (temp[1]).y2))
		{
			if ((temp[0]).x2 - (temp[0]).x1 >= (temp[1]).x2 - (temp[1]).x1)
			{
				(temp[2]).x2 = abs((temp[0]).x2);
			}
			else
			{
				(temp[2]).x2 = abs((temp[1]).x2);
			}
		}
		else
		{
			if ((temp[0]).x2 - (temp[0]).x1 >= (temp[1]).y1 - (temp[1]).y2)
			{
				(temp[2]).x2 = abs((temp[0]).x2);
			}
			else
			{
				(temp[2]).x2 = (temp[0]).x2 + ((temp[1]).y1 - (temp[1]).y2);
			}
		}
	}
	else
	{
		(temp[2]).x1 = abs((temp[0]).x1);
		(temp[2]).y2 = abs((temp[0]).y2);
		(((temp[1]).x2 - (temp[1]).x1) >= ((temp[1]).y1 - (temp[1]).y2) ? (temp[2].x2 = (temp[0]).x2 + ((temp[1]).y1 - (temp[1]).y2)) : (temp[2].x2 = (temp[0]).x2 + ((temp[1]).x2 - (temp[1]).x1)));
		if (((temp[1]).x2 - (temp[1]).x1) >= ((temp[1]).y1 - (temp[1]).y2))
		{
			if ((temp[0]).y1 - (temp[0]).y2 >= (temp[1]).x2 - (temp[1]).x1)
			{
				(temp[2]).y1 = abs((temp[0]).y1);
			}
			else
			{
				(temp[2]).y1 = (temp[0]).y2 + ((temp[1]).x2 - (temp[1]).x1);
			}
		}
		else
		{
			if ((temp[0]).y1 - (temp[0]).y2 >= (temp[1]).y1 - (temp[1]).y2)
			{
				(temp[2]).y1 = abs((temp[0]).y1);
			}
			else
			{
				(temp[2]).y1 = abs((temp[1]).y2);
			}
		}
	}
	cout << "координаты наименьшего общего прямоугольника, содержащего данные " << endl
		<< "A: (" << (temp[2]).x1 << ";" << (temp[2]).y1 << ")" << endl
		<< "B: (" << (temp[2]).x2 << ";" << (temp[2]).y1 << ")" << endl
		<< "C: (" << (temp[2]).x2 << ";" << (temp[2]).y2 << ")" << endl
		<< "D: (" << (temp[2]).x1 << ";" << (temp[2]).y2 << ")" << endl;
	delete[] temp;
}

void rectangle::change_size()
{
	int r;
	cout << "ввидите на сколько хотите изменить размер по вертикале: ";
	cin >> r;
	y1 = y1 + r;
	cout << "ввидите на сколько хотите изменить размер по горизонтали: ";
	cin >> r;
	x2 = x2 + r;
}

void rectangle::change_place()
{
	int d;
	cout << "ввидите на сколько хотите переместить по x: ";
	cin >> d;
	x1 = x1 + d;
	x2 = x2 + d;
	cout << "ввидите на сколько хотите переместить по y: ";
	cin >> d;
	y1 = y1 + d;
	y2 = y2 + d;
}

void rectangle::input()
{
	cout << "ввидите координату x левых точек: ";
	cin >> x1;
	cout << "ввидите координату y верхних точек: ";
	cin >> y1;
	cout << "ввидите координату x правых точек: ";
	cin >> x2;
	cout << "ввидите координату y нижних точек: ";
	cin >> y2;
}

void rectangle::output()
{
	cout << "координаты прямоугольника" << endl;
	cout << "A: (" << x1 << ";" << y1 << ")" << endl
		<< "B: (" << x2 << ";" << y1 << ")" << endl
		<< "C: (" << x2 << ";" << y2 << ")" << endl
		<< "D: (" << x1 << ";" << y2 << ")" << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	rectangle a;
	char choise;
	cout << "1)ввести значения " << endl
		<< "2)вывести координаты " << endl
		<< "3)изменить расположение " << endl
		<< "4)изменить размер " << endl
		<< "5)координаты наименьшего общего прямоугольника " << endl
		<< "6)Прямоугольник получившийся на пересечении 2 заданных " << endl
		<< "0)закрыть программу" << endl
		<< "!)вызвать меню " << endl
		<< ">";
	cin >> choise;
	while (choise)
	{
		switch (choise)
		{
		case'1':
		{
			a.input();
			break;
		}
		case '2':
		{
			a.output();
			break;
		}
		case '3':
		{
			a.change_place();
			break;
		}
		case '4':
		{
			a.change_size();
			break;
		}
		case '5':
		{
			a.least_rectangle();
			break;
		}
		case '6':
		{
			a.crossing();
			break;
		}
		case '!':
		{
			cout << "1)ввести значения " << endl
				<< "2)вывести координаты " << endl
				<< "3)изменить расположение " << endl
				<< "4)изменить размер " << endl
				<< "5)координаты наименьшего общего прямоугольника " << endl
				<< "6)прямоугольник получившийся при пересечении двух заданных" << endl
				<< "0)закрыть программу" << endl
				<< "!)вызвать меню " << endl;
			break;
		}
		case '0':
		{
			return 0;
		}
		}
		cout << ">";
		cin >> choise;
	}
	system("pause");
	return 0;
}