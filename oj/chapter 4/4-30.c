#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// 查找串 s 中第一次出现的最长重复子串及其位置
void findLongestRepeatedSubstring(char s[]) {
    int n = strlen(s);
    int maxLen = 0; // 最长重复子串的长度
    int startPos = -1; // 最长重复子串的起始位置

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int len = 0;
            int k = i;
            int l = j;
            // 检查从当前位置开始的重复子串的长度
            while (k < n && l < n && s[k] == s[l]) {
                len++;
                k++;
                l++;
            }
            // 更新最长重复子串信息
            if (len > maxLen) {
                maxLen = len;
                startPos = i;
            }
        }
    }

    // 输出结果
    if (maxLen > 0) {
        for (int i = startPos; i < startPos + maxLen; i++) {
            printf("%c", s[i]);
        }
        printf(" %d\n", startPos);
    }
    else {
        printf("-1\n");
    }
}

int main() {
    char s[MAX_LENGTH];

    scanf("%s", s);

    findLongestRepeatedSubstring(s);

    return 0;
}
