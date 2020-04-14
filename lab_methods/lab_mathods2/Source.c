#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

int newton(int n, double *x, double *y, double *c)
{
	int i, j, k;
	double temp1 = 0.0, temp2 = 0.0;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (x[i] == x[j])
				return 0;
		}
	}
	c[0] = y[0];
	for (i = 1; i < n; i++)
	{
		for (j = 1; j <= i - 1; j++)
		{
			for (k = 0; k <= j - 1; k++)
			{
				if (temp2 == 0.0 && k==0)
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
			if (temp2 == 0.0 && k==0)
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

void newton_polynomial(int n, double *c,double *x)
{
	double temp1=0.0, temp2=0.0, X;
	int i, j;
	FILE *fp;
	fp = fopen("result.txt", "w");
	temp1 = c[0];
	fprintf(fp, "y(%f)=%f\n", 0.0, temp1);
	for (X = 0.1; X <= 10; X = X + 0.1)
	{
		for (i = 1; i < n; i++)
		{
			for (j = 0; j <= i - 1; j++)
			{
				if (temp2 == 0.0 && j == 0)
				{
					temp2 = X - x[j];
				}
				else
				{
					temp2 = temp2 * (X - x[j]);
				}
			}
			temp1 = temp1 + c[i] * temp2;
			temp2 = 0.0;
		}
		fprintf(fp, "y(%f)=%f\n", X, temp1);
		temp1 = c[0];
	}
	fclose(fp);
}

int main(void)
{
	int n,i,tmp;
	double *x, *y, *c;
	FILE *s_x,*s_y;

	n = 11;
	x = (double*)malloc(n * sizeof(double));
	y = (double*)malloc(n * sizeof(double));
	c = (double*)malloc(n * sizeof(double));

	if ((s_x = fopen("x.txt", "r"))==NULL)
	{
		printf("can't open the file");
		getchar();
		return 0;
	}
	if ((s_y = fopen("y.txt", "r")) == NULL)
	{
		printf("can't open the file");
		getchar();
		return 0;
	}
	
	for (i = 0; i < n; i++)
	{
		fscanf(s_x, "%d", &tmp);
		x[i] = (double)tmp;
		fscanf(s_y, "%d", &tmp);
		y[i] = (double)tmp;
	}

	if (newton(n, x, y, c) == 0)
	{
		free(x);
		free(y);
		free(c);
		fclose(s_x);
		fclose(s_y);
		getchar();
		return 0;
	}

	newton_polynomial(n, c, x);
	for (i = 0; i < n; i++)
	{
		printf("c[%d]=%f\n",i ,c[i]);
	}

	free(x);
	free(y);
	free(c);
	fclose(s_x);
	fclose(s_y);
	getchar();
	return 0;
}