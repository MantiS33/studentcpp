#include <stdio.h>
#include <malloc.h>
#include <math.h>

int simple_iterations(double **a, double *b, double e , int n, double *x)
{
	double **A, *B, *Xpr, temp;
	int i, j;
	for (i = 0; i < n; i++)
	{
		temp = 0.0;
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				temp += fabs(a[i][j]);
			}
		}
		if (temp >= fabs(a[i][i]))
		{
			return 0;
		}
	}
	A = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
	{
		A[i] = (double*)malloc(n * sizeof(double));
	}
	B = (double*)malloc(n * sizeof(double));
	Xpr = (double*)malloc(n * sizeof(double));
	for (i = 0; i < n; i++)
	{
		temp = a[i][i];
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				A[i][j] = 0.0;
			}
			else
			{
				A[i][j] = -a[i][j] / temp;
			}
		}
		B[i]= Xpr[i] = b[i] / temp;
	}
	for (;;)
	{
		for (i = 0; i < n; i++)
		{
			x[i] = B[i];
			for (j = 0; j < n; j++)
			{
				x[i] += A[i][j] * Xpr[j];
			}
		}
		for (i = 0; i < n; i++)
		{
			if (fabs(x[i] - Xpr[i]) > e)
			{
				break;
			}
		}
		if (i == n)
		{
			break;
		}
		for (i = 0; i < n; i++)
		{
			Xpr[i] = x[i];
		}
	}
	for (i = 0; i < n; i++)
	{
		free(A[i]);
	}
	free(Xpr);
	free(B);
	free(A);
	return 1;
}

int main(void)
{
	int n, i;
	double **a, *b, *x;
	n = 4;
	a = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
	{
		a[i] = (double*)malloc(n * sizeof(double));
	}
	b = (double*)malloc(n * sizeof(double));
	x = (double*)malloc(n * sizeof(double));
	a[0][0] = 6.0; a[0][1] = 3.0; a[0][2] = -1.5; a[0][3] = 1.0;
	a[1][0] = -2.0; a[1][1] = -8.0; a[1][2] = 3.0; a[1][3] = -2.5;
	a[2][0] = 1.5; a[2][1] = -2.0; a[2][2] = -8.0; a[2][3] = 2.5;
	a[3][0] = -3.0; a[3][1] = -3.0; a[3][2] = 1.5; a[3][3] = 9.5;
	
	b[0] = 11.5; b[1] = -19.0; b[2] = -16.5; b[3] = 33.5;
	if (simple_iterations(a,b,2.72,n,x) == 0)
	{
		printf("%s", "Solution doesn't find.\n");
		free(x);
		free(b);
		for (i = 0; i < n; i++)
		{
			free(a[i]);
		}
		free(a);
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		printf("%f", x[i]);
		printf("%s", "\n");
	}
	free(x);
	free(b);
	for (i = 0; i < n; i++)
	{
		free(a[i]);
	}
	free(a);
	return 0;
}