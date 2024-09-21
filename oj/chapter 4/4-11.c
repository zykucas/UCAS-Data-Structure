#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <string.h>  
#include <stdbool.h>  

#define MAX_LEN 1000 

int main() {
    char s[MAX_LEN], t[MAX_LEN], r[MAX_LEN];
    bool seen_in_s[256] = { false }; 
    bool seen_in_t[256] = { false };
    int pos_in_s[256] = { -1 };   
    int i, j, r_len = 0;
 
    scanf("%s %s", s, t);

    for (i = 0; t[i] != '\0'; i++) {
        seen_in_t[(unsigned char)t[i]] = true;
    }

    for (i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (!seen_in_t[(unsigned char)c] && !seen_in_s[(unsigned char)c]) {
            r[r_len++] = c;
            seen_in_s[(unsigned char)c] = true;
            pos_in_s[(unsigned char)c] = i + 1;
        }
    }

    if (r_len == 0) {
        printf("-1\n");
    }
    else {
        r[r_len] = '\0';
        printf("%s ", r);
        for (i = 0; i < r_len; i++) {
            printf("%d", (pos_in_s[(unsigned char)r[i]]-1));
        }
        printf("\n");
    }

    return 0;
}
