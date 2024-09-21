#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 计数排序函数
void countingSort(int arr[], int n, int exp) {
    int output[1000];
    int count[1000] = { 0 };

    // 计数每个数字出现的次数
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 将计数数组转换为位置数组
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 从后向前遍历原始数组，将元素放入正确的位置
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 将排序好的结果拷贝回原始数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// 基数排序函数
void radixSort(int arr[], int n) {
    // 找出待排序序列中的最大值
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // 依次对个位、十位、百位...进行排序
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int n = 0;
    char c;
    int arr[1000];
    do {
        scanf("%d%c", &arr[n++], &c);
    } while (c != '\n');

    // 调用基数排序函数对序列进行排序
    radixSort(arr, n);

    // 输出排序完成后的序列
    for (int i = 0; i < n-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n-1]);
    return 0;
}
