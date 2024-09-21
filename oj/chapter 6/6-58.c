#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// 定义二叉树节点结构
typedef struct BinaryTree {
    int value;
    struct BinaryTree* left;
    struct BinaryTree* right;
} BinaryTree;

// 创建二叉树节点
BinaryTree* createBinaryTreeNode(int value) {
    BinaryTree *node = (BinaryTree*)malloc(sizeof(BinaryTree));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BinaryTree* buildTree(int *R,int *L,int index,int m) {
    BinaryTree* root = createBinaryTreeNode(index);
    root->left = (L[index - m] == 0) ? NULL : buildTree(R, L, L[index - m], m);
    root->right = (R[index - m] == 0) ? NULL : buildTree(R, L, R[index - m], m);
    return root;
}

// 在二叉树中查找值为x的节点
struct BinaryTree* findNode(struct BinaryTree* root, int x) {
    if (root == NULL) {
        return NULL; // 如果树为空，返回NULL
    }
    if (root->value == x) {
        return root; // 如果当前节点的值等于x，返回当前节点
    }

    // 在左子树中递归查找
    struct BinaryTree* leftResult = findNode(root->left, x);
    if (leftResult != NULL) {
        return leftResult; // 如果在左子树中找到了节点，直接返回结果
    }

    // 在右子树中递归查找
    struct BinaryTree* rightResult = findNode(root->right, x);
    if (rightResult != NULL) {
        return rightResult; // 如果在右子树中找到了节点，直接返回结果
    }

    return NULL; // 如果左右子树都没有找到节点，返回NULL
}

// 中序遍历打印二叉树
void inorderTraversal(struct BinaryTree* root,int *res,int *index) {
    if (root == NULL) {
        return; // 如果树为空，直接返回
    }

    // 递归遍历左子树
    inorderTraversal(root->left, res, index);

    // 打印当前节点的值
    res[*index] = root->value;
    (*index)++;

    // 递归遍历右子树
    inorderTraversal(root->right, res, index);
}

void freeTree(struct BinaryTree* root) {
    if (root == NULL) {
        return; // 如果树为空，直接返回
    }

    // 递归释放左子树
    freeTree(root->left);

    // 递归释放右子树
    freeTree(root->right);

    // 释放当前节点
    free(root);
}

int main() {

    // 二叉树的存储结构
    int L[MAX_NODES + 1] = { 0 }; // 左孩子数组
    int R[MAX_NODES + 1] = { 0 }; // 右孩子数组

    int dt;
    char c;
    int i = 0;
    do {
        scanf("%d%c", &dt, &c);
        L[i] = dt;
        i++;
    } while (c != '\n');

    i = 0;

    do {
        scanf("%d%c", &dt, &c);
        R[i] = dt;
        i++;
    } while (c != '\n');

    
    BinaryTree* root = buildTree(R, L, 1, 0);

    int p;
    scanf("%d", &p);

    // 二叉树的存储结构
    int L1[MAX_NODES + 1] = { 0 }; // 左孩子数组
    int R1[MAX_NODES + 1] = { 0 }; // 右孩子数组

    i = 0;

    do {
        scanf("%d%c", &dt, &c);
        L1[i] = dt;
        i++;
    } while (c != '\n');

    i = 0;

    do {
        scanf("%d%c", &dt, &c);
        R1[i] = dt;
        i++;
    } while (c != '\n');

    BinaryTree* root1 = buildTree(R1, L1, L1[0], L1[0] - 1);

    BinaryTree* r = findNode(root, p);
        
    root1->right = r->left;
    r->left = root1;

    int res[100] = { 0 };
    int index = 0;
    int* ptr = &index;

    inorderTraversal(root, res, ptr);

    i = 0;

    while (res[i+1] != 0)
    {
        printf("%d ", res[i]);
        i++;
    }

    printf("%d", res[i]);
   

    freeTree(root);

    return 0;
}
