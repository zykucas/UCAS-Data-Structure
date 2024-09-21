#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int key;
    struct ListNode* next;
};

bool search(struct ListNode* head, struct ListNode* tail, int k) {
    struct ListNode* current = head;

    do {
        if (current->key == k) {
            return true; // 查找成功
        }

        current = current->next;
    } while (current != tail && current->key <= k);

    return false; // 查找失败
}

int main() {
    // 构建一个有序的循环链表
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    char c;
    int data[100] = { 0 };
    int j = 1;
    int flag = 0;
    char ch = getchar();
    if (ch == '\n')
    {
        flag = 1;
    }
    else {
        data[0] = ch - '0';
    }
    
    if (flag == 0) {
        do {
            scanf("%d%c", &data[j], &c);
            j++;
         } while (c != '\n');
    }
    
    int num[20] = { 0 };
    int k = 0;
    do {
        scanf("%d%c", &num[k], &c);
        k++;
    } while (c != '\n');

    if (flag == 0) {
         for (int i = 0; i < j; i++) {
                struct ListNode* node = malloc(sizeof(struct ListNode));
                node->key = data[i];
                node->next = head;

                if (head == NULL) {
                    head = node;
                    tail = node;
                }
                else {
                    tail->next = node;
                    tail = node;
                }
            }
            tail->next = head; // 将链表变为循环链表
    }
   

    // 在链表中查找元素
    if (flag == 0) {
        bool found;
        for (int i = 0; i < k-1; i++) {
            found = search(head, tail, num[i]);
            printf("%d ", ((found == true) ? 1 : 0));
        }
        found = search(head, tail, num[k-1]);
        if (num[k - 1] == data[k - 1]) {
            printf("1");
        }
        else
        {
            printf("%d", ((found == true) ? 1 : 0));
        }
        

    }
    else
    {
        for (int i = 0; i < k - 1; i++) {
        
            printf("0 ");
        }
  
        printf("0");
    }
    

  
   
    if (flag == 0) {
     // 释放链表节点的内存
        struct ListNode* current = head;

        while (current != tail) {
            struct ListNode* temp = current;
            current = current->next;
            free(temp);
        }
        free(tail); // 释放尾节点的内存
    }
   

    return 0;
}
