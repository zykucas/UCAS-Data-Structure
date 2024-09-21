#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int StrCompare(char* S, char* T) {
    while (*S != '\0' && *T != '\0') {
        if (*S < *T) {
            return -1;
        }
        else if (*S > *T) {
            return 1;
        }
        S++;
        T++;
    }
    if (*S == '\0' && *T != '\0') {
        return -1;
    }
    else if (*S != '\0' && *T == '\0') {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char  S[100],  T[100];
    char c;
    int i = 0, j = 0;
    while ((c = getchar()) != ' ')
    {
        S[i] = c;
        i++;
    }
    S[i] = '\0';
 
    while ((c = getchar()) != '\n')
    {
        T[j] = c;
        j++;
    }
    T[j] = '\0';
   
    int result = StrCompare(S, T);
    printf("%d\n", result); 
    return 0;
}
