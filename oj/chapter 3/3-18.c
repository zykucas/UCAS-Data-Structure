#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdbool.h>  

bool isBalanced(const char* expr) {
    int count = 0;
    while (*expr) {
        if (*expr == '(') {
            count++;
        }
        else if (*expr == ')') {
            count--;
            if (count < 0) {
                return false; 
            }
        }
        expr++;
    }
    return count == 0;
}

int main() {
    char expr[100];
    scanf("%99s", expr); 
    if (isBalanced(expr)) {
        printf("1\n"); 
    }
    else {
        printf("0\n"); 
    }

    return 0;
}
