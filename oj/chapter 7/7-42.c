#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// 邻接表中的边结点
typedef struct EdgeNode {
    int dest; // 目标顶点
    int weight; // 边的权重
    struct EdgeNode* next; // 下一个边结点
} EdgeNode;

// 邻接表中的顶点结点
typedef struct VertexNode {
    EdgeNode* head; // 第一个边结点
} VertexNode;

// 图结构
typedef struct {
    int numVertices; // 图中顶点的数量
    VertexNode* array; // 邻接表的数组，每个元素表示一个顶点
} Graph;

// 创建边结点
EdgeNode* createEdgeNode(int dest, int weight) {
    EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// 创建图
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // 分配内存给邻接表数组
    graph->array = (VertexNode*)malloc(numVertices * sizeof(VertexNode));

    // 初始化邻接表中的顶点
    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// 添加边到图中
void addEdge(Graph* graph, int src, int dest, int weight) {
    // 添加边从src到dest
    EdgeNode* newNode = createEdgeNode(dest, weight);
    newNode->next = graph->array[src - 1].head;
    graph->array[src - 1].head = newNode;

    // 由于是无向图，也添加边从dest到src
    newNode = createEdgeNode(src, weight);
    newNode->next = graph->array[dest - 1].head;
    graph->array[dest - 1].head = newNode;
}

// Dijkstra算法
void dijkstra(Graph* graph, int src,int dest) {
    int numVertices = graph->numVertices;
    int* dist = (int*)malloc(numVertices * sizeof(int));
    bool* visited = (bool*)malloc(numVertices * sizeof(bool));
    int* prev = (int*)malloc(numVertices * sizeof(int));

    // 初始化所有顶点的距离为无穷大，且未访问过
    for (int i = 0; i < numVertices; ++i) {
        dist[i] = INF;
        visited[i] = false;
        prev[i] = -1;
    }

    // 设置源顶点到自身的距离为0
    dist[src - 1] = 0;

    // 找到源顶点到目标顶点的最短路径
    while (!visited[dest - 1]) {
        // 选取未访问过的顶点中距离最小的顶点
        int minDist = INF;
        int minIndex = -1;
        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        // 标记选取的顶点为已访问
        visited[minIndex] = true;

        // 更新选取顶点的邻接顶点的距离
        EdgeNode* current = graph->array[minIndex].head;
        while (current != NULL) {
            int destVertex = current->dest - 1;
            int weight = current->weight;
            if (!visited[destVertex] && dist[minIndex] != INF && dist[minIndex] + weight < dist[destVertex]) {
                dist[destVertex] = dist[minIndex] + weight;
                prev[destVertex] = minIndex;
            }
            current = current->next;
        }
    }

    printf("%d", dist[dest - 1]);

    free(dist);
    free(visited);
    free(prev);
}

int main() {
    int numVertices;
    int src, dest;

    scanf("%d %d\n", &numVertices, &src);

    Graph* graph = createGraph(numVertices);

    int dt1, dt2;
    char c,ch;

    while ((c = getchar()) != EOF)
    {
        scanf("-%d %d", &dt1, &dt2);
        ch = getchar();
        addEdge(graph, c-'0', dt1, dt2);
    }  
    
    int j = 1;
    for (dest = 1; dest <= numVertices; dest++)
    {
        if (dest != src&&j!=numVertices-1)
        {
            dijkstra(graph, src, dest);
            printf(",");
            j++;
        }
        else if (dest != src && j == numVertices - 1)
        {
            dijkstra(graph, src, dest);
        }
       
    }
    

    return 0;
}
