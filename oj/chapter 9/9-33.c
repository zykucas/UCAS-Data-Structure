#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int data[100];
	char c;
	int i = 0;
	do {
		scanf("%d%c", &data[i], &c);
		i++;
	} while (c != '\n');

	int a;
	scanf("%d", &a);

	int res[20];
	int k = 0;
	for (int j = i-1; j >=0; j--) {
		if (data[j] >= a) {
			res[k] = data[j];
			k++;
		}
	}

	for (int j = 0; j < k - 1; j++)
	{
		printf("%d ", res[j]);
	}
	printf("%d", res[k - 1]);

	return 0;
}
