#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef enum { Link, Thread } PointerTag; // Link = 0 表示指向左子树或右子树, Thread = 1 表示指向前驱或后继

// 定义二叉树节点结构
typedef struct BinaryTree {
    int value;
    struct BinaryTree* left;
    struct BinaryTree* right;
    PointerTag LTag, RTag;
} BinaryTree;

BinaryTree* pre = NULL; // 全局变量，用于指向当前节点的前驱节点

// 创建二叉树节点
BinaryTree* createBinaryTreeNode(int value) {
    BinaryTree* node = (BinaryTree*)malloc(sizeof(BinaryTree));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->LTag = Link;
    node->RTag = Link;
    return node;
}

BinaryTree* buildTree(int val[][4],int index) {
        val[index][3] = 0;
        BinaryTree* root = createBinaryTreeNode(val[index][0]);
        root->left = (val[index][1] == 0) ? NULL : buildTree(val, val[index][1]-1);
        root->right = (val[index][2] == 0) ? NULL : buildTree(val, val[index][2]-1);
        return root;
}

// 先序遍历并线索化二叉树
void preorderThread(BinaryTree* T) {
    if (T != NULL) {
        if (T->left == NULL) { // 如果当前节点没有左孩子
            T->LTag = Thread; // 设置左标志为线索
            T->left = pre; // 当前节点的左指针指向前驱节点
        }

        pre = T; // 保持pre指向当前访问节点

        if (T->LTag == Link) { // 如果左指针指向左孩子，则递归线索化左子树
            preorderThread(T->left);
        }
        preorderThread(T->right); // 线索化右子树
    }
}


// 递归先序遍历二叉树
void preorderRecursive_left(BinaryTree* root,int *L) {
    if (root == NULL) {
        return;
    }

    L[root->value] = (root->left == NULL) ? 0 : root->left->value;

    if (root->LTag == Link)
    {
        preorderRecursive_left(root->left,L); // 遍历左子树
    }
    
    if (root->RTag == Link)
    {
       preorderRecursive_left(root->right,L); // 遍历右子树
    }
    
}

// 递归先序遍历二叉树
void preorderRecursive_right(BinaryTree* root, int* R) {
    if (root == NULL) {
        return;
    }

    R[root->value] = (root->right==NULL) ? 0 : root->right->value;

    if (root->LTag == Link)
    {
        preorderRecursive_right(root->left, R); // 遍历左子树
    }

    if (root->RTag == Link)
    {
        preorderRecursive_right(root->right, R); // 遍历右子树
    }

    
}

// 中序遍历并线索化二叉树
void inorderThread(BinaryTree* T) {
    if (T != NULL) {
        inorderThread(T->left); // 线索化左子树

        if (T->left == NULL) { // 如果当前节点没有左孩子
            T->LTag = Thread; // 设置左标志为线索
            T->left = pre; // 当前节点的左指针指向前驱节点
        }
        if (pre != NULL && pre->right == NULL) { // 如果前驱节点存在且没有右孩子
            pre->RTag = Thread; // 设置前驱节点的右标志为线索
            pre->right = T; // 前驱节点的右指针指向当前节点
        }
        pre = T; // 保持pre指向当前访问节点

        inorderThread(T->right); // 线索化右子树
    }
}

// 后续线索化二叉树
void PostOrderThreading(BinaryTree* p) {
    if (p != NULL) {
       
        // 线索化左子树
        PostOrderThreading(p->left);
        // 线索化右子树
        PostOrderThreading(p->right);
        // 处理当前节点
        if (pre != NULL && pre->right == NULL) { // 前驱节点的右子树为空，建立后继线索
            pre->right = p;
            pre->RTag = Thread;
        }

        pre = p; // 移动前驱节点
    }
}

// 去除线索二叉树的线索
void removeThreads(BinaryTree* T) {
    if (T != NULL) {
        if (T->LTag == Thread) {
            T->left = NULL; // 去除左线索
            T->LTag = Link;
        }
        if (T->RTag == Thread) {
            T->right = NULL; // 去除右线索
            T->RTag = Link;
        }
        removeThreads(T->left); // 递归去除左子树的线索
        removeThreads(T->right); // 递归去除右子树的线索
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int values[100][4];
    BinaryTree* roots[10];
    int r = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &values[i][0], &values[i][1], &values[i][2]);
        values[i][3] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (values[i][3] == -1)
        {
            roots[r] = buildTree(values,i);
            r++;
        }
    }

    roots[r] = NULL;

    for (int i = 0; roots[i] != NULL; i++)
    {
        roots[i]->right = roots[i + 1];
    }

    pre = roots[0];

    preorderThread(roots[0]);

    int L1[100];
    L1[0] = 1;
    int R1[100];
    R1[0] = 1;

    preorderRecursive_left(roots[0], L1);
    preorderRecursive_right(roots[0], R1);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", L1[i]);
    }
    printf("%d\n", L1[n]);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", R1[i]);
    }
    printf("%d\n", R1[n]);

    removeThreads(roots[0]);
   
    pre = NULL;

    inorderThread(roots[0]);

    preorderRecursive_left(roots[0], L1);
    preorderRecursive_right(roots[0], R1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", L1[i]);
    }
    printf("%d\n", L1[n]);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", R1[i]);
    }
    printf("%d\n", R1[n]);

    removeThreads(roots[0]);

    pre= NULL;

    PostOrderThreading(roots[0]);

    preorderRecursive_left(roots[0], L1);
    preorderRecursive_right(roots[0], R1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", L1[i]);
    }
    printf("%d\n", L1[n]);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", R1[i]);
    }
    printf("%d", R1[n]);

    return 0;
}
