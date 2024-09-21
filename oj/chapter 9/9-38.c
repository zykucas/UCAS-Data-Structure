#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 定义二叉排序树的节点结构体
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// 创建新节点的函数
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入节点的函数
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// 中序遍历并打印节点值的函数
void inOrderTraversal(Node* root,int *res,int *index) {
    if (root != NULL) {
        inOrderTraversal(root->left, res, index);
        res[*index] = root->key;
        (*index)++;
        inOrderTraversal(root->right, res, index);
    }
}

// 中序遍历并释放节点的函数
void freeAndInOrderTraversal(Node* root) {
    if (root != NULL) {
        freeAndInOrderTraversal(root->left);
        free(root);
        freeAndInOrderTraversal(root->right);
    }
}

// 合并两棵二叉排序树的函数
Node* mergeTrees(Node* tree1, Node* tree2) {
    if (tree1 == NULL) {
        return tree2;
    }
    if (tree2 == NULL) {
        return tree1;
    }

    // 遍历第二棵树，将节点逐个插入到第一棵树中
    Node* current = tree2;
    while (current != NULL) {
        if (current->left == NULL) {
            tree1 = insert(tree1, current->key);
            Node* temp = current;
            current = current->right;
            free(temp);
        }
        else {
            Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            }
            else {
                predecessor->right = NULL;
                tree1 = insert(tree1, current->key);
                Node* temp = current;
                current = current->right;
                free(temp);
            }
        }
    }

    // 释放第二棵树的内存
    //freeAndInOrderTraversal(tree2);

    return tree1;
}

int main() {
    // 创建第一棵二叉排序树
    Node* tree1 = NULL;
    Node* tree2 = NULL;
    int dt;
    char c;
    do {
        scanf("%d%c", &dt, &c);
        if (dt != -1)
        {
            tree1 = insert(tree1, dt);
        }
    } while (c != '\n');

    do {
        scanf("%d%c", &dt, &c);
        if (dt != -1)
        {
            tree1 = insert(tree1, dt);
        }
    } while (c != '\n');

    // 合并两棵二叉排序树
    //Node* mergedTree = mergeTrees(tree1, tree2);
    int res[30] = { 0 };
    int index = 0;
    int* p = &index;

    // 打印合并后的结果
    inOrderTraversal(tree1, res, p);

    // 释放内存
    //freeAndInOrderTraversal(mergedTree);
    int k = 0;
    while (res[k+1] != 0)
    {
        printf("%d ", res[k]);
        k++;
    }
    printf("%d", res[k]);
    return 0;
}
