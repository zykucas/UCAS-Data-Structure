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

	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);

	int res[20];
	int k = 0;
	for (int j = 0; j < i; j++) {
		if (data[j] > a && data[j] < b) {
			res[k] = data[j];
			k++;
		}
	}

	for (int j = 0; j < k - 1; j++)
	{
		printf("%d ", res[j]);
	}
	printf("%d", res[k-1]);

	return 0;
}
