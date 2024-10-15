#include <stdio.h>
#include <stdlib.h>

// 연결리스트
struct Node {
    int vertex;
    struct Node *next;
};

struct Graph {
    struct Node **adjLists;
    int vertices;
};

struct Graph *createGraph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->adjLists = (struct Node **)malloc((vertices+1) * sizeof(struct Node *));
    for (int i = 1; i <= vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
};

struct Node *createNode(int vertex) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
};

void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    graph->vertices++;
}

// 위상 정렬
int *inDegree;
int *ans, ansIdx;

void topologicalSort(struct Graph *graph, int vertices) {
    int *queue = (int *)malloc(vertices * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 1; i <= vertices; i++) {
        if (inDegree[i] == 0) queue[rear++] = i;
    }

    while (front < rear) {
        int cur = queue[front++];
        ans[ansIdx++] = cur;

        struct Node *temp = graph->adjLists[cur];
        while (temp != NULL) {
            int curVertex = temp->vertex;
            inDegree[curVertex]--;
            if (inDegree[curVertex] == 0)
                queue[rear++] = curVertex;
            temp = temp->next;
        }
    }

    free(queue);
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    struct Graph *graph = createGraph(N);
    inDegree = (int *)calloc(N+1, sizeof(int));
    ans = (int *)malloc(N * sizeof(int));

    int singerNum, cur, prev;
    for (int i = 0; i < M; i++) {
        scanf("%d", &singerNum);

        scanf("%d", &prev);
        for (int j = 1; j < singerNum; j++) {
            scanf("%d", &cur);
            addEdge(graph, prev, cur);
            inDegree[cur]++;
            prev = cur;
        }
    }

    topologicalSort(graph, N);
    if (ansIdx != N) putchar('0');
    else for (int i = 0; i < N; i++) printf("%d\n", ans[i]);

    for (int i = 1; i <= N; i++) {
        struct Node *temp = graph->adjLists[i];
        while (temp) {
            struct Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
    free(inDegree);

    return 0;
}