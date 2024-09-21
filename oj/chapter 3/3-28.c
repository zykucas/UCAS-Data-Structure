#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
/*
// 定义队列节点的结构体  
typedef struct QNode {
    int data;
    struct QNode* next;
} QNode, * QueuePtr;

// 初始化队列  
void InitQueue(QueuePtr* rear) {
    *rear = (QueuePtr)malloc(sizeof(QNode)); // 创建头结点  
    if (!(*rear)) {
        exit(1); // 分配内存失败  
    }
    (*rear)->next = *rear; // 指向自己，形成循环链表  
}

// 入队操作  
void EnQueue(QueuePtr* rear, int x) {
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode)); // 创建新结点  
    if (!p) {
        exit(1); // 分配内存失败  
    }
    p->data = x;
    p->next = (*rear)->next; // 新结点插入到队尾  
    (*rear)->next = p;
    *rear = p; // 更新尾指针  
}

// 出队操作  
int DeQueue(QueuePtr* rear) {
    if (*rear == (*rear)->next) {
        return -1; // 队列为空  
    }
    QueuePtr p = (*rear)->next; // 取出队首元素  
    int x = p->data;
    (*rear)->next = p->next; // 删除队首元素  
    if (*rear == p) {
        *rear = (*rear)->next; // 更新尾指针  
    }
    free(p); // 释放结点  
    return x;
}

int main() {
    int n, x;
    QueuePtr rear = NULL;
    char buffer[1024];
    char* token;

    // 初始化队列  
    InitQueue(&rear);

    // 读取队列个数  
    scanf("%d", &n);
    getchar(); // 读取换行符  

    // 读取入队列的元素序列  
    fgets(buffer, sizeof(buffer), stdin);
    token = strtok(buffer, ",");
    while (token != NULL) {
        sscanf(token, "%d", &x);
        EnQueue(&rear, x);
        token = strtok(NULL, ",");
    }

    // 出队列并输出结果  
    printf("出队列的元素序列：");
    while (n--) {
        x = DeQueue(&rear);
        if (x != -1) {
            printf("%d", x);
            if (n > 0) {
                printf(",");
            }
        }
    }
    printf("\n");

    // 释放队列空间  
    QueuePtr p, q;
    p = rear->next;
    while (p != rear) {
        q = p;
        p = p->next;
        free(q);
    }
    free(rear);

    return 0;
}
*/

int main()
{
    int num;
    scanf("%d\n", &num);

    char str[100];

    scanf("%s", str);
    printf("%s", str);
    
}
