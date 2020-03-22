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
	int n, i, j;
	double **a; *b, *x;


}