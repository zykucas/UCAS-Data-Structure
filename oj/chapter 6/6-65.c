#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 二叉树结点的结构体定义
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 根据先序序列和中序序列构建二叉树
TreeNode* buildTree(char* preorder, char* inorder, int inorderStart, int inorderEnd) {
    static int preorderIndex = 0; // 用于记录当前处理的先序序列的索引
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    // 创建当前结点
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = preorder[preorderIndex++];
    root->left = NULL;
    root->right = NULL;

    // 在中序序列中找到当前结点的位置
    int inorderIndex;
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (inorder[i] == root->data) {
            inorderIndex = i;
            break;
        }
    }

    // 递归构建左子树和右子树
    root->left = buildTree(preorder, inorder, inorderStart, inorderIndex - 1);
    root->right = buildTree(preorder, inorder, inorderIndex + 1, inorderEnd);

    return root;
}

// 后序遍历二叉树
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c", root->data);
}

int main() {
    // 读取输入的先序序列和中序序列
    char preorder[100], inorder[100];
    scanf("%s", preorder);
    scanf("%s", inorder);

    // 构建二叉树
    TreeNode* root = buildTree(preorder, inorder, 0, strlen(inorder) - 1);

    postorderTraversal(root);
    printf("\n");

    return 0;
}
