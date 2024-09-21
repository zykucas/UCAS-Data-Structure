#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 结点结构体
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// 图结构体
typedef struct {
    int numVertices;
    Node** adjLists;
} Graph;

// 创建结点
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 创建图
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // 创建邻接表
    graph->adjLists = (Node**)malloc((vertices + 1) * sizeof(Node*));
    for (int i = 1; i <= vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// 添加边
void addEdge(Graph* graph, int src, int dest) {
    // 添加从src到dest的边
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // 由于是无向图，需要添加从dest到src的边
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// 深度优先搜索
bool DFS(Graph* graph, int src, int dest, int len, bool visited[]) {
    if (src == dest && len == 0)
        return true;

    if (len <= 0)
        return false;

    visited[src] = true;
    Node* temp = graph->adjLists[src];
    while (temp != NULL) {
        if (!visited[temp->vertex] && DFS(graph, temp->vertex, dest, len - 1, visited))
            return true;
        temp = temp->next;
    }

    visited[src] = false;
    return false;
}

// 判断是否存在给定长度的路径
bool hasPathWithLength(Graph* graph, int src, int dest, int len) {
    bool* visited = (bool*)malloc((graph->numVertices + 1) * sizeof(bool));
    for (int i = 1; i <= graph->numVertices; i++) {
        visited[i] = false;
    }
    bool result = DFS(graph, src, dest, len, visited);
    free(visited);
    return result;
}

int main() {
    int vertices;
    int src, dest, len;
    scanf("%d,%d", &vertices,&len);
    
    scanf("%d,%d", &src, &dest);

    Graph* graph = createGraph(vertices);

    int dt1, dt2;
    char c;
    do {
        scanf("%d-%d%c", &dt1, &dt2, &c);
        addEdge(graph, dt1, dt2);
    } while (c != '\n');
    
    if (hasPathWithLength(graph, src, dest, len)) {
        printf("yes");
    }
    else {
        printf("no");
    }

    return 0;
}
