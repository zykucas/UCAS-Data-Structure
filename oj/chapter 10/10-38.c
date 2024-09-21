#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// 归并两个有序链表
ListNode* merge(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode));
    ListNode* current = dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        }
        else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1) current->next = l1;
    if (l2) current->next = l2;

    ListNode* result = dummy->next;
    free(dummy);
    return result;
}

// 划分最大有序子列并归并排序
ListNode* mergeSort(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    // 快慢指针找到中间节点
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 切分为两个子链表
    ListNode* secondHalf = slow->next;
    slow->next = NULL;

    // 递归对两个子链表进行归并排序
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(secondHalf);

    // 归并两个有序链表
    return merge(left, right);
}

int main() {
    // 读取输入的数据元素个数
    int n;
    scanf("%d", &n);

    // 创建链表
    ListNode* head = NULL;
    ListNode* current = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = val;
        node->next = NULL;
        if (head == NULL) {
            head = node;
            current = node;
        }
        else {
            current->next = node;
            current = node;
        }
    }

    // 使用2-路归并排序策略对链表进行排序
    ListNode* sortedList = mergeSort(head);

    // 输出排序后的数据元素序列
    current = sortedList;
    while (current->next != NULL) {
        printf("%d ", current->val);
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    printf("%d", current->val);

    return 0;
}
