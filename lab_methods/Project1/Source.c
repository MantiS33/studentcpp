#include <stdio.h>
#define PRINT \
for (int i = 0; i < n; i++)\
{\
for (int j = 0; j < n + 1; j++)\
{\
printf("%f", ab[i][j]);\
printf(" ");\
}\
printf("\n");\
}\
printf("\n");\

int GaussianElimination(const int n, const double** a, const double* b, double* x);
int JordanMethod(const int n, const double** a, const double* b, double* x);
int LU(const int n, const double** a, const double* b, double* x);

int main()
{
	double** a = (double**)malloc(3 * sizeof(double*));
	for (int i = 0; i < 3; i++)
		a[i] = (double*)malloc(3 * sizeof(double));
	a[0][0] = 3; a[0][1] = -3; a[0][2] = 3;
	a[1][0] = 2; a[1][1] = 2; a[1][2] = -2;
	a[2][0] = 1; a[2][1] = 1; a[2][2] = 1;

	double* b = (double*)malloc(3 * sizeof(double));
	b[0] = 3; b[1] = 2; b[2] = 3;
	double* x = (double*)malloc(3 * sizeof(double));
	for (int i = 0; i < 3; i++)
		x[i] = 0;

	/*printf("Метод Гаусса.\n");
	if (GaussianElimination(3, a, b, x))
	{
		printf("Вектор решения:\n");
		for (int i = 0; i < 3; i++)
		{
			printf("%f", x[i]);
			printf(" ");
		}
		printf("\n");
	}
	else printf("Решений нет или их бесконечное множество.");

	printf("\n\n\n");*/

	printf("Метод Жордана.\n");
	if (JordanMethod(3, a, b, x))
	{
		printf("Вектор решения:\n");
		for (int i = 0; i < 3; i++)
		{
			printf("%f", x[i]);
			printf(" ");
		}
		printf("\n");
	}
	else printf("Решений нет или их бесконечное множество.");


}

int GaussianElimination(const int n, const double** a, const double* b, double* x)
{
	double** ab = (double**)malloc(n * sizeof(double*));

	for (int i = 0; i < n; i++)
	{
		ab[i] = (double*)malloc((n + 1) * sizeof(double));

		for (int j = 0; j < n; j++)
			ab[i][j] = a[i][j];

		ab[i][n] = b[i];
	}

	printf("Расширенная матрица:\n");
	PRINT

		for (int i = 0; i < n; i++)
		{
			if (ab[i][i] == 0)
			{
				for (int i = 0; i < n; i++)
					free(ab[i]);
				free(ab);
				return 0;
			}

			for (int j = n; j >= 0; j--)
			{
				ab[i][j] /= ab[i][i];

				for (int k = i + 1; k < n; k++)
				{
					ab[k][j] -= ab[i][j] * ab[k][i];
				}
			}
		}

	printf("Матрица с единичной диагональю:\n");
	PRINT

		for (int i = n - 1; i >= 0; i--)
		{
			x[i] = ab[i][n];
			for (int j = n - 1; j > i; j--)
			{
				x[i] -= ab[i][j] * x[j];
			}
		}

	for (int i = 0; i < n; i++)
		free(ab[i]);
	free(ab);

	return 1;
}

int JordanMethod(const int n, const double** a, const double* b, double* x)
{
	double** ab = (double**)malloc(n * sizeof(double*));

	for (int i = 0; i < n; i++)
	{
		ab[i] = (double*)malloc((n + 1) * sizeof(double));

		for (int j = 0; j < n; j++)
			ab[i][j] = a[i][j];

		ab[i][n] = b[i];
	}

	printf("Расширенная матрица:\n");
	PRINT

		for (int i = 0; i < n; i++)
		{
			if (ab[i][i] == 0)
			{
				for (int i = 0; i < n; i++)
					free(ab[i]);
				free(ab);
				return 0;
			}

			for (int j = n; j >= 0; j--)
			{
				ab[i][j] /= ab[i][i];

				for (int k = 0; k < n; k++)
				{
					if (k == i) continue;
					ab[k][j] -= ab[i][j] * ab[k][i];
				}
			}
		}

	printf("Матрица со всеми преобразованиями:\n");
	PRINT

		for (int i = 0; i < n; i++)
		{
			x[i] = ab[i][n];
		}

	for (int i = 0; i < n; i++)
		free(ab[i]);
	free(ab);

	return 1;
}

int LU(const int n, const double** a, const double* b, double* x)
{

}