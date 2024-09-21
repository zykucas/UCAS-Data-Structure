#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <string.h>  

void reverseString(char* str, int length) {
    if (length <= 1) {
        return; 
    }

    char temp = str[0];
    str[0] = str[length - 1];
    str[length - 1] = temp;
 
    reverseString(str + 1, length - 2);
}

int main() {
    char str[100];
    char c; 
    int length=0;
    while ((c=getchar())!='\n')
    {
        str[length] = c;
        length++;
    }
    str[length] = '\0';
   
    reverseString(str, length);

    //for (int i = 0; i < length; i++)
    //{
    //    printf("%d ", str[i]);
    //}

    //printf("\n%d", length);
    printf("%s", str);
    return 0;
}
