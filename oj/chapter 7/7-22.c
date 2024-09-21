#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// 定义邻接表中的节点结构
struct ListNode {
    int vertex;
    struct ListNode* next;
};

// 定义图结构
struct Graph {
    int numVertices;
    struct ListNode* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
};

// 创建邻接表中的节点
struct ListNode* createListNode(int v) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 创建图
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; ++i) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

// 添加边
void addEdge(struct Graph* graph, int src, int dest) {
    // 添加从src到dest的边
    struct ListNode* newNode = createListNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// 深度优先搜索函数
bool dfs(struct Graph* graph, int start, int end) {
    // 标记当前顶点为已访问
    graph->visited[start] = true;

    // 如果当前顶点为目标顶点，则返回true
    if (start == end)
        return true;

    // 遍历当前顶点的邻居顶点
    struct ListNode* adjList = graph->adjLists[start];
    while (adjList != NULL) {
        int neighbor = adjList->vertex;
        // 如果邻居顶点未被访问，则递归调用dfs
        if (!graph->visited[neighbor]) {
            if (dfs(graph, neighbor, end))
                return true;
        }
        adjList = adjList->next;
    }

    // 如果所有邻居顶点都被访问过，并且没有找到目标顶点，则返回false
    return false;
}

// 判断是否存在从start到end的路径
bool hasPath(struct Graph* graph, int start, int end) {
    // 调用深度优先搜索函数来检查是否存在从start到end的路径
    return dfs(graph, start, end);
}

// 释放图的内存
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; ++i) {
        struct ListNode* adjList = graph->adjLists[i];
        while (adjList != NULL) {
            struct ListNode* temp = adjList;
            adjList = adjList->next;
            free(temp);
        }
    }
    free(graph);
}

int main() {
    int v;
    scanf("%d", &v);
    // 创建图
    struct Graph* graph = createGraph(v);

    int v1, v2;
    char c;
    do {
        scanf("%d-%d%c", &v1, &v2, &c);
        addEdge(graph, v1, v2);
    } while (c != '\n');

    int m, n;
    scanf("%d,%d", &m, &n);
   
    // 定义起始顶点和目标顶点
    int startVertex = m;
    int endVertex = n;
    // 调用函数判断是否存在从起始顶点到目标顶点的路径
    if (hasPath(graph, startVertex, endVertex)) {
        printf("yes");
    }
    else {
        printf("no");
    }
    // 释放图的内存
    freeGraph(graph);
    return 0;
}
