#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAXINT 0xFFFFFFFF
#define MAX_ARR_SIZE 20

bool factorial_multiply_overflow(int i) {
    int factorial = 1;
    for (int j = 1; j <= i; ++j) {
        if (factorial > MAXINT / j) {
            return true;
        }
        factorial *= j;
    }

    if (factorial > MAXINT >> i) {
        return true;
    }

    return false;
}

void calculate_and_store_results(int n, int arrsize, int* a) {
    for (int i = 0; i < n && i < arrsize; ++i) {
        int factorial = 1;
        if (factorial_multiply_overflow(i)) {
            a[i] = -1;   
        }
        else 
        {
            for (int j = 1; j <= i; ++j) {
                factorial *= j;
            }

            a[i] = factorial << i;
        }
    }
}

int main() {
    int n, arrsize;
    scanf("%d %d", &n, &arrsize);

    if (arrsize > MAX_ARR_SIZE || n < 0) {
        printf("-1\n");
        return 0;
    }
    
    if (n > arrsize)
    {
        printf("-1\n");
        return 0;
    }

    int a[MAX_ARR_SIZE];
    calculate_and_store_results(n, arrsize, a);
    int tmp = 0;

    for (int k = 0; k < n; k++)
    {
        if (a[k] < 0)
        {
            tmp += 1;
        }
    }

    if (tmp > 0)
    {
        printf("-1\n");
        return 0;
    }
    else
    {
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        printf("\n");
        return 0;
    }
}
