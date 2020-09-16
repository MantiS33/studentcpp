#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

double lagr(int n, double* xt, double* yt, double x)
{
	int i, j, k;
	double tmp = 1.0, tmp2;
	for (i = 0; i < ((n - 1) / 0.1 + 1.0); i++)
	{
		tmp2 = 0.0;
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (k == j)
				{
					continue;
				}
				tmp = tmp * ((x - xt[k]) / (xt[j] - xt[k]));
			}
			tmp2 = tmp2 + (yt[j] * tmp);
			tmp = 1.0;
		}
	}
	return tmp2;
}

int main(void)
{
	FILE *inFileXt, *inFileYt, *outFileResult;
	int i, n;
	double *xt, *yt, x;
	scanf("%d", &n);
	if ((inFileXt = fopen("xt.txt", "r")) == NULL)
	{
		printf("%s\n", "can't open the file");
		fclose(inFileXt);
		getchar();
		return 0;
	}
	if ((inFileYt = fopen("yt.txt", "r")) == NULL)
	{
		printf("%s\n", "can't open the file");
		fclose(inFileXt);
		fclose(inFileYt);
		getchar();
		return 0;
	}

	xt = (double*)malloc(n * sizeof(double));
	yt = (double*)malloc(n * sizeof(double));

	for (i = 0; i < n; i++)
	{
		fscanf(inFileXt, "%lf", &xt[i]);
		fscanf(inFileYt, "%lf", &yt[i]);
	}
	for (i = 0; i < n; i++)
	{
		printf("y(%f)=%f\n", xt[i], yt[i]);
	}
	outFileResult = fopen("result.txt", "w");
	for (x = .0; x <= (n-1); x = x + 0.1)
	{
		fprintf(outFileResult, "y(%f)=%f\n", x, lagr(n,xt,yt,x));
	}
	free(xt);
	free(yt);
	fclose(outFileResult);
	fclose(inFileXt);
	fclose(inFileYt);
	getchar();
	return 0;
}