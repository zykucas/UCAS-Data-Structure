#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 100



// 判断节点 u 是否为节点 v 的子孙
bool isDescendant(int v, int u, int* L, int* R) {
    if (v == 0) { // 如果 v 为空，则 u 也为空，无法为其子孙
        return false;
    }
    if (v == u) { // 如果 v 就是 u 本身，则 u 是 v 的子孙
        return true;
    }
    // 递归判断左右孩子是否为 u 的子孙
    return isDescendant(L[v], u, L, R) || isDescendant(R[v], u, L, R);
}

int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

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

    L[0] = 1;
    R[0] = 1;

    int v, u;
    scanf("%d %d", &u, &v);

    // 判断节点 u 是否为节点 v 的子孙，并输出结果
    if (v != u)
    {
        if (isDescendant(v, u, L, R)) {
            printf("%d", 1);
        }
        else {
            printf("%d", 0);
        }
    }
    else { printf("%d", 0); }


    return 0;
}
