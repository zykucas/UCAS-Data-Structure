#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  

void main() 
{
	char a[100];
	char b[100];
	char c;
	int i = 0, j = 0;
	do {
		scanf("%c%c", &a[i],&c);
		i++;
	} while (c != '\n');

	a[i] = '\0';

	do {
		scanf("%c%c", &b[j],&c);
		j++;
	} while (c != '\n');

	b[j] = '\0';

	int length1, length2, len;

	length1 = strlen(a);
	length2 = strlen(b);
	len = (length1 <= length2) ? length1 : length2;

	int flag = 0;

	for (int k = 0; k < len; k++)
	{
		if (a[k] < b[k])
		{
			flag = 1;
			break;
		}
		else if (a[k] > b[k])
		{
			flag = 2;
			break;
		}
		else
		{
			k++;
		}
	}

	if (flag == 0)
	{
		if (length1 == length2)
		{
			printf("0");

		}
		else if (length1 < length2)
		{
			printf("1");
		}
		else
		{
			printf("2");
		}
	}
	else {
		printf("%d", flag);
	}

}
