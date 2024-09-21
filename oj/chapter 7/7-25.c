#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // 最大顶点数

// 邻接表中的边节点
struct EdgeNode {
    int dest;
    struct EdgeNode* next;
};

// 邻接表中的顶点节点
struct VertexNode {
    struct EdgeNode* head; // 指向该顶点的边链表的头指针
};

// 有向图结构
struct DirectedGraph {
    int numVertices; // 顶点数
    struct VertexNode* vertices[MAX_VERTICES]; // 邻接表数组
};

// 创建一个有向图
struct DirectedGraph* createGraph(int numVertices) {
    struct DirectedGraph* graph = (struct DirectedGraph*)malloc(sizeof(struct DirectedGraph));
    graph->numVertices = numVertices;

    // 初始化邻接表中的顶点
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i] = (struct VertexNode*)malloc(sizeof(struct VertexNode));
        graph->vertices[i]->head = NULL;
    }

    return graph;
}

// 添加一条有向边
void addEdge(struct DirectedGraph* graph, int src, int dest) {
    struct EdgeNode* newNode = (struct EdgeNode*)malloc(sizeof(struct EdgeNode));
    newNode->dest = dest - 1; // 将顶点编号减1
    newNode->next = graph->vertices[src - 1]->head; // 将顶点编号减1
    graph->vertices[src - 1]->head = newNode; // 将顶点编号减1
}

// 深度优先搜索函数
int isCyclicUtil(int v, int visited[], int recStack[], struct DirectedGraph* graph) {
    if (visited[v] == 0) {
        visited[v] = 1;
        recStack[v] = 1;

        // 遍历当前顶点的邻接表
        struct EdgeNode* current = graph->vertices[v]->head;
        while (current != NULL) {
            int dest = current->dest;
            if (!visited[dest] && isCyclicUtil(dest, visited, recStack, graph)) {
                return 1;
            }
            else if (recStack[dest]) {
                return 1;
            }
            current = current->next;
        }
    }
    recStack[v] = 0;
    return 0;
}

// 判断图是否包含回路
int isCyclic(struct DirectedGraph* graph) {
    int visited[MAX_VERTICES] = { 0 }; // 记录顶点是否被访问过
    int recStack[MAX_VERTICES] = { 0 }; // 记录递归调用栈中的顶点

    // 对每个顶点执行深度优先搜索
    for (int i = 0; i < graph->numVertices; i++) {
        if (isCyclicUtil(i, visited, recStack, graph)) {
            return 1;
        }
    }
    return 0;
}

// 释放图的内存
void freeGraph(struct DirectedGraph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct EdgeNode* current = graph->vertices[i]->head;
        while (current != NULL) {
            struct EdgeNode* temp = current;
            current = current->next;
            free(temp);
        }
        free(graph->vertices[i]);
    }
    free(graph);
}

// 测试程序
int main() {
    int v;
    scanf("%d", &v);

    int s[100], fst[100], lst[100];
    int i = 0;
    char c;
    do {
        scanf("%d%c", &s[i], &c);
        i++;
    } while (c != '\n');

    i = 0;

    do {
        scanf("%d%c", &fst[i], &c);
        i++;
    } while (c != '\n');

    i = 0;

    do {
        scanf("%d%c", &lst[i], &c);
        i++;
    } while (c != '\n');

    // 创建图
    struct DirectedGraph* graph = createGraph(v);
    // 添加边
    for (int m = 1; m <= v; m++)
    {
        if (fst[m] < lst[m])
        {
            for (int j = fst[m]; j < lst[m]; j++)

            {
                addEdge(graph, m, s[j]);
            }
        }
    }


    // 判断图是否包含回路
    if (isCyclic(graph)) {
        printf("yes");
    }
    else {
        printf("no");
    }

    // 释放图的内存
    freeGraph(graph);

    return 0;
}
