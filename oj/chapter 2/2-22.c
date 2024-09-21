#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

typedef struct ListNode {
    char val;
    struct ListNode* next;
} ListNode;
 
ListNode* createNode(char val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) {
        return NULL;
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

ListNode* buildListFromString(char* elements) {
    if (!elements) return NULL;

    ListNode dummy;
    ListNode* tail = &dummy;
    dummy.next = NULL;

    char* token = strtok(elements, ",");
    while (token) {
        tail->next = createNode(token[0]);
        tail = tail->next;
        token = strtok(NULL, ",");
    }
    return dummy.next;
}

void reverseList(ListNode** head) {
    ListNode* prev = NULL;
    ListNode* curr = *head;
    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    *head = prev;
}

char* listToString(ListNode* head) {
    if (!head) return NULL;

    int length = 0;
    ListNode* curr = head;
 
    while (curr) {
        length++;
        curr = curr->next;
    }
  
    char* result = (char*)malloc((length * 2) + 1); 
    if (!result) return NULL;

    int index = 0;
    curr = head;
    while (curr) {
        result[index++] = curr->val;
        if (curr->next) {
            result[index++] = ',';
        }
        curr = curr->next;
    }
    result[index] = '\0';  
    return result;
}
  
void freeList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        ListNode* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    char elements[100];
    scanf("%s", elements);
    ListNode* head = buildListFromString(elements);

    char* originalListStr = listToString(head);
    free(originalListStr);

    reverseList(&head);

    char* reversedListStr = listToString(head);
    printf("%s\n", reversedListStr);
    free(reversedListStr);  

    freeList(head); 
    return 0;
}
