#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int matrix[MAXSIZE][MAXSIZE] = { 0 };

	for (int i = 0; i < x; i++)
	{
		int dt;
		char c;
		int k = 0;
		do {
			scanf("%d%c", &dt, &c);
			matrix[i][k] = dt;
			k++;
		} while (c != '\n');
	}

	int m, n;
	for (m = 0; m < x; m++)
	{
		for (n = 0; n < y; n++)
		{
			if (matrix[m][n] != 0) { goto next; }
		}
	}
	next: for (int i = x - 1; i >= m; i--)
	{
		for (int j = y - 1; j >= n; j--)
		{
			if (i != m || j != n)
			{
				if (matrix[i][j] != 0)
				{
					if (i != 0 && j != 0)
					{
						if (matrix[i][j] != 1)
						{
							printf("%dxE%dyE%d+", matrix[i][j], i, j);
						}
						else {
							printf("xE%dyE%d+", i, j);
						}

					}
					else if (i == 0 && j != 0)
					{
						if (matrix[i][j] != 1)
						{
							printf("%dyE%d+", matrix[i][j], j);
						}
						else {
							printf("yE%d+", j);
						}
					}
					else if (i != 0 && j == 0)
					{
						if (matrix[i][j] != 1)
						{
							printf("%dxE%d+", matrix[i][j], i);
						}
						else {
							printf("xE%d+", i);
						}
					}

				}
			}
			else
			{
				if (matrix[i][j] != 0)
				{
					if (i != 0 && j != 0)
					{
						if (matrix[i][j] != 1)
						{
							printf("%dxE%dyE%d", matrix[i][j], i, j);
						}
						else {
							printf("xE%dyE%d", i, j);
						}

					}
					else if (i == 0 && j != 0)
					{
						if (matrix[i][j] != 1)
						{
							printf("%dyE%d", matrix[i][j], j);
						}
						else {
							printf("yE%d", j);
						}
					}
					else if (i != 0 && j == 0)
					{
						if (matrix[i][j] != 1)
						{
							printf("%dxE%d", matrix[i][j], i);
						}
						else {
							printf("xE%d", i);
						}
					}
					else if (i == 0 && j == 0)
					{

						printf("%d", matrix[i][j]);

					}



				}
			}

		}
	}
	return 0;
}
