#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;

    while (mid <= high) {
        switch (nums[mid]) {
        case 1: // 如果当前元素为红色，则与low位置的元素交换，并将low和mid都向后移动一位
            swap(&nums[mid], &nums[low]);
            low++;
            mid++;
            break;
        case 2: // 如果当前元素为白色，则只需将mid向后移动一位
            mid++;
            break;
        case 3: // 如果当前元素为蓝色，则与high位置的元素交换，并将high向前移动一位
            swap(&nums[mid], &nums[high]);
            high--;
            break;
        }
    }
}

void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize-1; i++) {
        printf("%d ", nums[i]);
    }
    printf("%d", nums[numsSize - 1]);
}

int main() {
    int nums[100];
    int numsSize;

    numsSize = 0;
    int color;
    char c;
    do {
        scanf("%d%c", &nums[numsSize++], &c);
    } while (c != '\n');

    sortColors(nums, numsSize);

    printArray(nums, numsSize);

    return 0;
}
