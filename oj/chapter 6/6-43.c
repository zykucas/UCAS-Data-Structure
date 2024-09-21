#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char L[100]; 
	char R[100];

	int i = 0;
	char c;
	do {
		scanf("%c",&c);
		L[i] = c;
		i++;
	} while (c != '\n');

	L[i-1] = '\0';
	i = 0;

	do {
		scanf("%c",&c);
		R[i] = c;
		i++;
	} while (c != '\n');

	R[i-1] = '\0';

	printf("%s\n", R);
	printf("%s", L);

	return 0;
}
