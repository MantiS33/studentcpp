#include "pch.h"
#include <iostream>
using namespace std;

int function()
{
	cout << "Ввидите 5 чисел: ";
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		arr[i] = (arr[i] * 2 - arr[i] + arr[i] * (arr[i] / 2)) / arr[i] / 5;
	}
	int f = arr[0] * arr[2] - arr[1] / arr[3] + arr[3] * (arr[4] - arr[0]) - arr[1];
	return f;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int result = function();
	cout << "результат: " << result << endl;
	system("pause");
	return 0;
}