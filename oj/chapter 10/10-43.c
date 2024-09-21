#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 计数排序函数
void countingSort(int a[], int c[], int n) {
    int count;

    for (int i = 0; i < n; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] < a[i]) {
                count++;
            }
        }
        c[i] = count;
    }
}

int main() {
    int n = 0;
    char ch;

    int a[1000], c[1000];

    do {
        scanf("%d%c", &a[n++], &ch);
    } while (ch != '\n');

    // 调用计数排序函数
    countingSort(a, c, n);

    // 输出c中每个元素
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", c[i]);
    }
    printf("%d", c[n - 1]);

    return 0;
}
