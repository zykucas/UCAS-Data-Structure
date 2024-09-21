#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// 定义二叉树节点
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


// 创建新的二叉树节点
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* buildTree(int* L, int* R,int *num, int index) {
    struct TreeNode* root = createNode(num[index]);
    root->left = (L[index] == -1) ? NULL : buildTree(L, R, num, L[index]);
    root->right = (R[index] == -1) ? NULL : buildTree(L, R, num, R[index]);
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


bool is_bst_util(struct TreeNode* node, int min_val, int max_val) {
    if (node == NULL) {
        return true;
    }

    if (node->data <= min_val || node->data >= max_val) {
        return false;
    }

    return (is_bst_util(node->left, min_val, node->data) &&
        is_bst_util(node->right, node->data, max_val));
}

bool is_binary_search_tree(struct TreeNode* root) {
    return is_bst_util(root, INT_MIN, INT_MAX);
}

int main() {
    int L[100], R[100], num[100];
    char ch, c, chr;
    int i = 0;
    while ((ch = getchar()) != EOF)
    {
        chr = getchar();
        if (chr != ' ') {
            num[i] = (10 * (ch - '0') + (chr - '0'));
        }
        else {
            num[i] = ch - '0';
        }
        scanf("%d%d", L + i, R + i);
       
        c = getchar();
        i++;
    }

    struct TreeNode* root = buildTree(L, R, num, 0);



    if (is_binary_search_tree(root)) {
        printf("1");
    }
    else {
        printf("0");
    }

    // 释放二叉树的内存

    freeTree(root);

    return 0;
}
