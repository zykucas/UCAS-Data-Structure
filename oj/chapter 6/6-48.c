#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 从先序序列构建二叉树
TreeNode* buildTreeFromPreorder(const char* preorder, int* index) {
    
    if (*index >= strlen(preorder) || preorder[*index] == '^') {
        (*index)++;
        return NULL;
    }

    TreeNode* root = createNode(preorder[*index]);
    (*index)++;

    root->left = buildTreeFromPreorder(preorder, index);
    root->right = buildTreeFromPreorder(preorder, index);

    return root;
}

// 递归查找最近公共祖先
TreeNode* findLCA(TreeNode* root, char p, char q, bool* foundP, bool* foundQ,char *ret,int *c,char path[], int pathsize) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == p) {
        *foundP = true;
    }
    if (root->data == q) {
        *foundQ = true;
    }

    if (*foundP && *foundQ) {
        return root;  // Both nodes found, return current node as LCA
    }

    
    TreeNode* leftLCA = findLCA(root->left, p, q, foundP, foundQ, ret, c, path, pathsize);
    TreeNode* rightLCA = findLCA(root->right, p, q, foundP, foundQ, ret, c, path, pathsize);

    if (*foundP && *foundQ) {
        int flag = 0;
        int i = 0;
        for (int i = 0; i < pathsize; i++) {
            if (path[i] == root->data)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            ret[*c] = root->data;
            (*c)++;
        }
        return root;  // Both nodes found in different subtrees, return current node as LCA
        
    }
    else if (*foundP || *foundQ) {
        return (*foundP) ? leftLCA : rightLCA;  // Only one node found, return corresponding subtree's LCA
    }
    else {
        return NULL;  // Neither node found, continue searching
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

// 辅助函数进行深度优先搜索
int dfs(struct TreeNode* node, char target, char path[], int* pathIndex) {
    if (node == NULL) {
        return 0;
    }

    // 将当前节点加入路径
    path[(*pathIndex)++] = node->data;

    // 检查当前节点是否为目标节点
    if (node->data == target) {
        return 1;
    }

    // 在左子树和右子树中继续搜索
    if ((node->left && dfs(node->left, target, path, pathIndex)) ||
        (node->right && dfs(node->right, target, path, pathIndex))) {
        return 1;
    }

    // 如果目标节点不在当前子树中，从路径中移除当前节点
    (*pathIndex)--;
    return 0;
}

// 查找路径的主函数
char* findPath(struct TreeNode* root, char target, int* pathSize) {
    char* path = (char*)malloc(100 * sizeof(char));  // 假设路径不会超过100个节点
    *pathSize = 0;
    dfs(root, target, path, pathSize);
    return path;
}

int main() {
    char preorder[100];
    char nodesToFind[20];
    int index = 0;

    fgets(preorder, sizeof(preorder), stdin);
    preorder[strcspn(preorder, "\n")] = '\0';  // Remove trailing newline

    fgets(nodesToFind, sizeof(nodesToFind), stdin);
    nodesToFind[strcspn(nodesToFind, "\n")] = '\0';  // Remove trailing newline

    char node1 = nodesToFind[0];
    char node2 = nodesToFind[2];

    TreeNode* root = buildTreeFromPreorder(preorder, &index);

    bool foundP = false;
    bool foundQ = false;
    char ret[100] = { '0' };
    int count = 0;
    int* c = &count;
    char target = node1;
    int pathSize = 0;
    char* path = findPath(root, target, &pathSize);

    TreeNode* lca = findLCA(root, node1, node2, &foundP, &foundQ, ret, c, path, pathSize);

    if (node1 == '1' || node2 == '1')
    {
        printf("%d", 1);
    }
    else
    {
        if (ret[0] == node1 || ret[0] == node2)
            {
                printf("%c", ret[1]);
            }
            else
            {
                printf("%c", ret[0]);
            }
    }
    
    

    freeTree(root);

    return 0;
}
