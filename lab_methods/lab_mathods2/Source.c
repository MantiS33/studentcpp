#include <stdio.h>
#include <math.h>
#include <malloc.h>

int newton(int n, double *x, double *y, double *c)
{
	int i, j, k;
	double temp1 = 0.0, temp2 = 0.0;
	c[0] = y[0];
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= i - 1; j++)
		{
			for (k = 0; k <= j - 1; k++)
			{
				if (temp2 == 0.0)
				{
					temp2 = x[i] - x[k];
				}
				else
				{
					temp2 = temp2 * (x[i] - x[k]);
				}
			}
			temp1 = temp1 + c[j] * temp2;
			temp2 = 0.0;
		}
		for (k = 0; k <= i - 1; k++)
		{
			if (temp2 == 0.0)
			{
				temp2 = x[i] - x[k];
			}
			else
			{
				temp2 = temp2 * (x[i] - x[k]);
			}
		}
		c[i] = (y[i] - c[0] - temp1) / temp2;
		temp1 = 0.0;
		temp2 = 0.0;
	}
	return 1;
}

int main(void)
{
	int n,i;
	double *x, *y, *c;
	n = 11;
	x = (double*)malloc(n * sizeof(double));
	y = (double*)malloc(n * sizeof(double));
	c = (double*)malloc(n * sizeof(double));
	for (i = 0; i < n; i++)
	{
		x[i] = (double)i;
	}
	y[0] = 10.0; y[1] = 2.0; y[2] = 1.0; y[3] = 1.0; y[4] = 1.0; y[5] = 1.0; y[6] = 2.0; y[7] = 1.0; y[8] = 0.0; y[9] = -1.0; y[10] = -10.0;
	if (newton(n, x, y, c) == 0)
	{
		free(x);
		free(y);
		free(c);
		getchar();
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		printf("%f\n", c[i]);
	}
	free(x);
	free(y);
	free(c);
	getchar();
	return 0;
}