#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int invmatr(int n, const double **a, double **b)
{
	int i, j, k, y;
	double **T, **tmp;
	double temp;
	T = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
	{
		T[i] = (double*)malloc((2*n) * sizeof(double));
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			T[i][j] = a[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = n; j < 2 * n; j++)
		{
			if (i == (j - n))
			{
				T[i][j] = 1.0;
			}
			else
			{
				T[i][j] = 0.0;
			}
		}
	}
	y = 0;
	for (i = 0; i < n; i++)
	{
		if (T[i][i] == .0)
		{
			continue;
		}
		temp = T[i][i];
		for (j = 0; j < 2 * n; j++)
		{
			T[i][j] = T[i][j] / temp;
		}

		for (j = 0; j < n; j++)
		{
			if (j == i)
			{
				continue;
			}
			
			if (T[j][i] != .0)
			{
				temp = T[j][i];
				for (k = y; k < 2 * n; k++)
				{
					T[j][k] = T[j][k] - T[i][k] * temp;
				}
			}
		}
		y = y + 1;
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = n; j < 2 * n; j++)
		{
			b[i][j-n] = T[i][j];
		}
	}
	
	tmp = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
	{
		tmp[i] = (double*)malloc(n * sizeof(double));
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			tmp[i][j] = .0;
			for (k = 0; k < n; k++)
			{
				tmp[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (tmp[i][i] != 1.0 && (tmp[i][i] > 1.0000001 || tmp[i][i] < 0.999999))
		{
			for (i = 0; i < n; i++)
			{
				free(T[i]);
			}
			free(T);
			for (j = 0; j < n; j++)
			{
				free(tmp[j]);
			}
			free(tmp);
			return 0;
		}
	}

	for (i = 0; i < n; i++)
	{
		free(T[i]);
	}
	free(T);
	for (i = 0; i < n; i++)
	{
		free(tmp[i]);
	}
	free(tmp);
	return 1;
}

/*int testmatr(int n, const double** a, const double** b)
{
	int i, j, k;
	double **temp;
	temp = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
	{
		temp[i] = (double*)malloc(n * sizeof(double));
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			temp[i][j] = 0;
			for (k = 0; k < n ; k++)
			{
				temp[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}
		
	for (i = 0; i < n; i++)
	{
		if (temp[i][i] != 1.0 && temp[i][i] > 1.0000001 && temp[i][i]<0.999999)
		{
			for (j = 0; j < n; j++)
			{
				free(temp[j]);
			}
			free(temp);
			return 1;
		}
	}

	for (i = 0; i < n; i++)
	{
		free(temp[i]);
	}
	free(temp);
	return 0;
}*/

int main(void)
{
	FILE *inFileA, *outFileB;
	int n, i, j;
	double **a, **b;
	printf("%s", "enter system order: ");
	scanf("%d", &n);
	a = (double**)malloc(n * sizeof(double*));
	b = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
	{
		a[i] = (double*)malloc(n * sizeof(double));
	}
	for (i = 0; i < n; i++)
	{
		b[i] = (double*)malloc(n * sizeof(double));
	}
	
	if ((inFileA = fopen("a.txt", "r")) == NULL)
	{
		printf("%s\n", "can't open the file");
		for (i = 0; i < n; i++)
		{
			free(a[i]);
		}
		for (i = 0; i < n; i++)
		{
			free(b[i]);
		}
		free(a);
		free(b);
		fclose(inFileA);
		getchar();
		return 0;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			fscanf(inFileA, "%lf", &a[i][j]);
			printf("%8.2f", a[i][j]);
		}
		printf("%c\n", ' ');
	}
	printf("%c\n",' ');
		
	if (invmatr(n, a, b) == 1)
	{
		outFileB = fopen("b.txt", "w");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%8.2f", b[i][j]);
				printf("%c", ' ');
				fprintf(outFileB, "%lf\n", b[i][j]);
			}
			printf("%c\n", ' ');
		}
		fclose(outFileB);
	}
	else
	{
		printf("%s\n", "failed to invert the matrix");
	}

	for (i = 0; i < n; i++)
	{
		free(a[i]);
	}
	for (i = 0; i < n; i++)
	{
		free(b[i]);
	}
	free(a);
	free(b);
	fclose(inFileA);
	getchar();
	return 0;
}