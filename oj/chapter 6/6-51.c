#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 创建新节点
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 根据先序序列构建二叉树
TreeNode* constructTree(char* preorder, int* index) {
    if (preorder[*index] == '\0' || preorder[*index] == '#') {
        (*index)++;
        return NULL;
    }

    TreeNode* root = createNode(preorder[*index]);
    (*index)++;

    root->left = constructTree(preorder, index);
    root->right = constructTree(preorder, index);

    return root;
}

int operator_get_index(const char C)
{
    switch (C)
    {
    case '+':
        return 0;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 3;
        break;
    case '(':
        return 4;
        break;
    case ')':
        return 5;
        break;
    default:
        return 6;
        break;
    }
}

char priority(const char C, const char D)
{
    static const char Priority[][7] = {
        '>', '>', '<', '<', '<', '>', '>',
        '>', '>', '<', '<', '<', '>', '>',
        '>', '>', '>', '>', '<', '>', '>',
        '>', '>', '>', '>', '<', '>', '>',
        '<', '<', '<', '<', '<', '=', '*', /* * is error */
        '>', '>', '>', '>', '*', '>', '>',
        '<', '<', '<', '<', '<', '*', '='
    };
    return Priority[operator_get_index(C)][operator_get_index(D)];
}


void tree_print_inorder(const TreeNode* T)
{
    if (T != NULL)
    {
        if (T->left != NULL && !isalnum(T->left->data) && priority(T->left->data, T->data) == '<')
        {
            putchar('(');
            tree_print_inorder(T->left);
            putchar(')');
        }
        else
            tree_print_inorder(T->left);
        putchar(T->data);
        if (T->right != NULL && !isalnum(T->right->data) && priority(T->data, T->right->data) == '>')
        {
            putchar('(');
            tree_print_inorder(T->right);
            putchar(')');
        }
        else
            tree_print_inorder(T->right);
    }
}

// 递归释放二叉树节点内存
void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);

    free(root);
}

int main() {
    // 给定的先序序列
    char preorder[100] ;

    fgets(preorder, sizeof(preorder), stdin);
    preorder[strcspn(preorder, "\n")] = '\0';

    int index = 0;
    TreeNode* root = constructTree(preorder, &index);

    tree_print_inorder(root);
    printf("\n");

    // 释放内存
    freeTree(root);

    return 0;
}

