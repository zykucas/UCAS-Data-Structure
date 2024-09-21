#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义二叉树节点
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 定义队列节点
struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

// 定义队列结构
struct Queue {
    struct QueueNode* front, * rear;
};

// 创建空队列
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// 入队列
void enqueue(struct Queue* q, struct TreeNode* value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// 出队列
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

// 判断二叉树是否为完全二叉树
bool isCompleteBinaryTree(struct TreeNode* root) {
    // 如果根节点为空，直接返回false
    if (root == NULL)
        return true;

    // 创建一个队列并将根节点入队列
    struct Queue* q = createQueue();
    enqueue(q, root);

    bool flag = false; // 用于标记是否遇到空节点

    // 开始遍历队列中的节点
    while (q->front != NULL) {
        struct TreeNode* current = dequeue(q);

        // 如果遇到空节点，并且后面的节点不都是空节点，则不是完全二叉树
        if (current == NULL) {
            flag = true;
            continue;
        }
        else if (flag) {
            return false;
        }

        // 将当前节点的左右子节点加入队列
        enqueue(q, current->left);
        enqueue(q, current->right);
    }

    // 遍历完所有节点后，如果都符合完全二叉树的条件，则返回true
    return true;
}

// 创建新的二叉树节点
struct TreeNode* createNode(char value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* buildTree(int *L,int *R, int index) {
    struct TreeNode* root = createNode((char)('A' + index - 1));
    root->left = (L[index] == -1) ? NULL : buildTree(L, R, L[index]);
    root->right = (R[index] == -1) ? NULL : buildTree(L, R, R[index]);
    return root;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

int main() {
    int L[100], R[100];
    char ch, c;
    while ((ch=getchar())!= EOF)
    {
        scanf("%d%d", L + ch - 'A' + 1, R + ch - 'A' + 1);
        c = getchar();
    }

    struct TreeNode* root = buildTree(L, R, 1);

   
    // 判断是否为完全二叉树并输出结果
    if (isCompleteBinaryTree(root)) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    // 释放二叉树的内存
    
    freeTree(root);

    return 0;
}
