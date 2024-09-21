#include <stdio.h>  
#include <stdlib.h>  

#define MAX_SIZE 100  

void insert(int va[], int* size, int x) {
    int i;
 
    for (i = 0; i < *size && va[i] < x; i++);
  
    for (int j = *size; j > i; j--) {
        va[j] = va[j - 1];
    }

    va[i] = x;

    (*size)++;
}

int main() {
    int va[MAX_SIZE];
    int size = 0;
    int x;

    char c;
    while ((c = getchar()) != '\n' && size < MAX_SIZE) {
        if (c >= '0' && c <= '9') {
            ungetc(c, stdin);  
            scanf("%d", &va[size]);
            size++;
        }
    }

    scanf("%d", &x);

    insert(va, &size, x);

    for (int i = 0; i < size; i++) {
        printf("%d ", va[i]);
    }
    printf("\n");

    return 0;
}
