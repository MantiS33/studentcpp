#include <stdio.h>
#include <malloc.h>
#include <math.h>

int slau(double **a, double *b, double e , int n, double *x)
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
	FILE *inFileA,*inFileB, *outFile;
	int n, i, j;
	double **a, *b, *x, e;
	printf("%s", "enter system order: ");
	scanf("%d", &n);
	printf("e = ");
	scanf("%lf", &e);
	a = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
	{
		a[i] = (double*)malloc(n * sizeof(double));
	}
	b = (double*)malloc(n * sizeof(double));
	x = (double*)malloc(n * sizeof(double));
	
	if ((inFileA = fopen("a.txt", "r")) == NULL)
	{
		printf("%s", "can't open the file");
		free(b);
		free(x); for (i = 0; i < n; i++)
		{
			free(a[i]);
		}
		fclose(inFileA);
		free(a);
		return 0;
	}
	if ((inFileB = fopen("b.txt", "r")) == NULL)
	{
		printf("%s", "can't open the file");
		free(b);
		free(x); for (i = 0; i < n; i++)
		{
			free(a[i]);
		}
		free(a);
		fclose(inFileA);
		fclose(inFileB);
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fscanf(inFileA, "%lf", &a[i][j]);
			printf("%8.2fx%i", a[i][j], j + 1);
		}
		fscanf(inFileB, "%lf", &b[i]);
		printf("%8.2f\n", b[i]);
	}

	
	if (slau(a,b,e,n,x) == 0)
	{
		printf("%s", "Solution doesn't find.\n");
		free(x);
		free(b);
		for (i = 0; i < n; i++)
		{
			free(a[i]);
		}
		free(a);
		fclose(inFileA);
		fclose(inFileB);
		return 0;
	}
	printf("\n");
	outFile = fopen("x.txt", "w");
	for (i = 0; i < n; i++)
	{
		printf("x%i=%lf\n", i + 1, x[i]);
		fprintf(outFile, "%lf\n", x[i]);
	}

	free(x);
	free(b);
	for (i = 0; i < n; i++)
	{
		free(a[i]);
	}
	free(a);
	fclose(inFileA);
	fclose(inFileB);
	fclose(outFile);
	return 0;
}