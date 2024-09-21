#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	int matrix[100][100];
	char ch;
	for (int i = 0; i < a; i++)
	{
		int j = 0;
		do {
			scanf("%d%c", &matrix[i][j],&ch);
			j++;
		} while (ch != '\n');
		
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (matrix[i][j] == 1)
			{
				matrix[i][j] = 2;
			}
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
