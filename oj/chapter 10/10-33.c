#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建一个新的节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表末尾添加一个节点
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 实现简单选择排序
void selectionSort(Node** head) {
    Node* current = *head;
    Node* index;
    Node* minNode;
    int min;

    while (current != NULL) {
        min = current->data;
        minNode = current;
        index = current->next;

        while (index != NULL) {
            if (index->data < min) {
                min = index->data;
                minNode = index;
            }
            index = index->next;
        }

        // 交换数据
        int temp = current->data;
        current->data = minNode->data;
        minNode->data = temp;

        current = current->next;
    }
}

// 打印链表
void printList(Node* head) {
    while (head->next != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d", head->data);
}

// 释放链表内存
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int data;
    char c;
    // 读取输入数据
    do {
        scanf("%d%c", &data, &c);
        append(&head, data);
    } while (c != '\n');
    
    // 执行简单选择排序
    selectionSort(&head);

    // 打印排序后的链表
    printList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}
