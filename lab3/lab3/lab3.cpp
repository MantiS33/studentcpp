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

void print(int& num)
{
	node*tmp = first;
	while (tmp != NULL)
	{
		if (tmp->value == num)
		{
			ofstream out("d://output.txt");
			out << "this number is in the file." << endl;
			out.close();
		}
		else
		{
			ofstream out("d://output.txt");
			out << "this number is not in the file.";
			out.close();
		}
		tmp = tmp->next;
	}
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
	int num;
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
		add_last(temp);
	}
	in.close();
	print(num);
	cout << endl;
	remove();
	system("pause");
	return 0;
}