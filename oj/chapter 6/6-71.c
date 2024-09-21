#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义树节点
struct TreeNode {
    char data;
    struct TreeNode* leftChild;
    struct TreeNode* rightSibling;
};

// 打印凹入表形式的树（先序遍历）
void printIndentedTreePreorder(struct TreeNode* root, int level) {
    if (root == NULL)
        return;

    // 打印当前节点
    for (int i = 0; i < level; i++)
        printf("-"); // 每一层缩进四个空格
    printf("%c\n", root->data);

    // 打印左孩子子树
    printIndentedTreePreorder(root->leftChild, level + 1);

    // 打印右兄弟子树
    printIndentedTreePreorder(root->rightSibling, level);
}

// 创建新的树节点
struct TreeNode* createNode(char value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->leftChild = NULL;
    newNode->rightSibling = NULL;
    return newNode;
}

struct TreeNode* buildTree(int* L, int* R, int index) {
    struct TreeNode* root = createNode((char)('A' + index - 1));
    root->leftChild = (L[index] == -1) ? NULL : buildTree(L, R, L[index]);
    root->rightSibling = (R[index] == -1) ? NULL : buildTree(L, R, R[index]);
    return root;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->leftChild);
    freeTree(root->rightSibling);

    free(root);
}

int main() {
    int L[100], R[100];
    char ch, c;
    while ((ch = getchar()) != EOF)
    {
        scanf("%d%d", L + ch - 'A' + 1, R + ch - 'A' + 1);
        c = getchar();
    }

    struct TreeNode* root = buildTree(L, R, 1);

// 打印凹入表形式的树（先序遍历）
    printIndentedTreePreorder(root, 0);

    
    // 释放二叉树的内存

    freeTree(root);

   
    
    return 0;
}
