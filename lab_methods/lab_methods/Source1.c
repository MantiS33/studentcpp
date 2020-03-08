#include <stdio.h>
#include <malloc.h>

int SLAU(int n, double** a, double* b, double* x)
{
	double**_a = (double**)malloc(n * sizeof(double*));
	
	for (int i = 0; i < n; i++)
	{
		_a[i] = (double*)malloc((n + 1) * sizeof(double));
	}
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			_a[i][j] = a[i][j];
		}
		_a[i][3] = b[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j >= 0; j--)
		{
			_a[i][j] = _a[i][j] / _a[i][i];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%f", _a[i][j]);
			printf("%c", ' ');
		}
		printf("%s", "\n\n");
	}

	free(_a);
	return 1;
}

int main()
{
	double** a = (double**)malloc(3 * sizeof(double*));
	for (int i = 0; i < 3; i++)
	{
		a[i] = (double*)malloc(3 * sizeof(double));
	}
	
	a[0][0] = 3; a[0][1] = -3; a[0][2] = 3;
	a[1][0] = 2; a[1][1] = 2; a[1][2] = -2;
	a[2][0] = 1; a[2][1] = 1; a[2][2] = 1;

	double* b = (double*)malloc(3 * sizeof(double));
	b[0] = 3; b[1] = 2; b[2] = 3;
	double* x = (double*)malloc(3 * sizeof(double));
	x[0] = 0; x[1] = 0; x[2] = 0;

	
	if (SLAU(3, a, b, x))
	{
		printf("%s", "\n");
	}
	
	for (int i = 0; i < 3; i++)
	{
		free(a[i]);
	}
	free(a);
	free(b);
	free(x);
	return 0;
}