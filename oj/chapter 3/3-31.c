#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>  

bool isPalindrome(char* str) {
    int length = strlen(str);
    int left = 0;
    int right = length - 2; 

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    char str[100];
    int i = 0;

    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("1\n");  
    }
    else {
        printf("0\n");
    }

    return 0;
}
