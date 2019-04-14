#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int value;
	node *next;
};

node*first = NULL;

void add_last(int value)
{
	node*tmp = new node;
	tmp->value = value;
	tmp->next = NULL;
	if (first == NULL)
	{
		first = tmp;
		return;
	}
	node*last = first;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	last = tmp;
}

void m_value(double& num)
{
	int count = 0;
	node*tmp = first;
	while (tmp != NULL)
	{
		num = num + tmp->value;
		count += 1;
		tmp = tmp->next;
	}
	num = num / count;
}

void remove()
{
	while (first != NULL)
	{
		node*tmp = first;
		first = first->next;
		delete tmp;
	}
	first = NULL;
}

int main()
{
	double num=0;
	ifstream in("d://input.txt");
	if (!in)
	{
		cout << "error openning the file" << endl;
	}
	while (!in.eof())
	{
		int temp;
		in >> temp;
		add_last(temp);
	}
	in.close();
	m_value(num);
	ofstream out("d://output.txt");
	out <<"Среденее арифметическое суммы чисел = " <<num << endl;
	out.close();
	remove();
	system("pause");
	return 0;
}