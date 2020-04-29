#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int newton(int n, double* x, double* y, double* c)
{
	int i, j,factorial=1;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (x[i] == x[j])
				return 0;
		}
	}
	double **deltaY, h;
	deltaY = (double**)malloc(n * sizeof(double*));
	for (i = 0; i < n; i++)
	{
		deltaY[i] = (double*)malloc(n * sizeof(double));
	}
	for (i = 0; i < n; i++)
	{
		deltaY[i][0] = y[i];
	}
	for (j = 1; j < n; j++)
	{
		for (i = 0; i < n - j; i++)
		{
			deltaY[i][j] = deltaY[i + 1][j - 1] - deltaY[i][j - 1];
		}
	}
	h = x[1] - x[0];
	c[0] = y[0];
	for (i = 1; i < n; i++)
	{
		factorial  *= i;
		c[i] = deltaY[0][i] / (factorial*pow(h, i));
	}
	for (i = 0; i < n; i++)
	{
		free(deltaY[i]);
	}
	free(deltaY);
	return 1;
}

void newtonPolynomial(int n, double* c, double* x)
{
	double temp1 = 0.0, temp2 = 1.0, X;
	int i, j;
	FILE* fp;
	fp = fopen("result.txt", "w");
	temp1 = c[0];
	fprintf(fp, "y(%f)=%f\n", 0.0, temp1);
	for (X = 0.1; X <= 10; X = X + 0.1)
	{
		for (i = 1; i < n; i++)
		{
			for (j = 0; j <= i - 1; j++)
			{
				
				temp2 = temp2 * (X - x[j]);
			}
			temp1 = temp1 + c[i] * temp2;
			temp2 = 1.0;
		}
		fprintf(fp, "y(%f)=%f\n", X, temp1);
		temp1 = c[0];
	}
	fclose(fp);
}

int main(void)
{
	int n, i;
	double *x, *y, *c;
	FILE *sFileX, *sFileY;

	scanf("%d", &n);
	x = (double*)malloc(n * sizeof(double));
	y = (double*)malloc(n * sizeof(double));
	c = (double*)malloc(n * sizeof(double));

	if ((sFileX = fopen("x.txt", "r")) == NULL)
	{
		printf("%s","can't open the file\n");
		free(x);
		free(y);
		free(c);
		fclose(sFileX);
		getchar();
		return 0;
	}
	if ((sFileY = fopen("y.txt", "r")) == NULL)
	{
		printf("%s","can't open the file\n");
		free(x);
		free(y);
		free(c);
		fclose(sFileY);
		fclose(sFileX);
		getchar();
		return 0;
	}

	for (i = 0; i < n; i++)
	{
		fscanf(sFileX, "%lf", &x[i]);
		fscanf(sFileY, "%lf", &y[i]);
	}

	if (newton(n, x, y, c) == 0)
	{
		free(x);
		free(y);
		free(c);
		fclose(sFileX);
		fclose(sFileY);
		getchar();
		return 0;
	}

	newtonPolynomial(n, c, x);
	for (i = 0; i < n; i++)
	{
		printf("c[%d]=%f\n", i, c[i]);
	}

	free(x);
	free(y);
	free(c);
	fclose(sFileX);
	fclose(sFileY);
	getchar();
	return 0;
}