#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* computeLPSArray(const char* pattern) {
    int patternLen = strlen(pattern);
    int* lps = (int*)malloc(sizeof(int) * patternLen);
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < patternLen) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int KMP(const char* text, const char* pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    int* lps = computeLPSArray(pattern);

    int i = 0;
    int j = 0;
    while (i < textLen) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == patternLen) {
            free(lps);
            return i - j; // 匹配成功，返回目标串在待搜索串中的位置
        }
        else if (i < textLen && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    free(lps);
    return -1; // 匹配失败，返回-1
}

int main() {
    int len1, len2;
    scanf("%d%d", &len1, &len2);

    char text[100];
    char pattern[50];
    scanf("%s", text);
    scanf("%s", pattern);

    int result = KMP(text, pattern);
    if (result == -1) {
        printf("-1");
    }
    else {
        printf("%d", result);
    }

    return 0;
}
