#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  

unsigned int F_recursive(unsigned int n) {
    if (n == 0) {
        return 1; 
    }
    else {
        return n * F_recursive(n / 2);
    }
}

int main() {
    unsigned int n;
    printf("");
    scanf("%d", &n);

    unsigned int result = F_recursive(n);
    printf("%d\n",result);

    return 0;
}
