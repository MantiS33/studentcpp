#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int num;
	bool test = false;
	cin >> num;
	ifstream in("d://input.txt");
	if (!in)
	{
		cout << "error openning the file" << endl;
	}
	while (!in.eof())
	{
		int temp;
		in >> temp;
		if (temp == num)
		{
			test = true;
		}
	}
	in.close();
	if (test == true)
	{
		ofstream out("d://output.txt");
		out << "this number is in the file" << endl;
		out.close();
	}
	else
	{
		ofstream out("d://output.txt");
		out << "this number is not in the file." << endl;
		out.close();
	}
	system("pause");
	return 0;
}