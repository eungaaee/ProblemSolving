#include <stdio.h>
#include <stdlib.h>

// 연결 리스트
// 노드 구조체
struct Node {
    int vertex;
    struct Node *next;
};

// 그래프 구조체
struct Graph {
    struct Node **adjLists; // 이차원 배열 느낌이 아니라, Node 구조체 포인터 배열 느낌
    int *inDegree; // 위상 정렬을 위한 진입 차수 배열
};

// 그래프 생성 함수
struct Graph *createGraph(int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));
    graph->inDegree = (int *)malloc(vertices * sizeof(int));

    for (int i = 1; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->inDegree[i] = 0;
    }

    return graph;
}

// 노드 생성 함수
struct Node *createNode(int vertex) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// 간선 추가 함수
void addEdge(struct Graph *graph, int src, int dest) {
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src]; // newNode의 (struct *Node)next를 (struct *Node)adjLists[src]로 설정하고
    graph->adjLists[src] = newNode; // adjLists[src]를 다시 newNode로 설정해놓기
}

// 위상 정렬
void topologicalSort(struct Graph *graph, int vertices) {
    int* queue = (int *)malloc(vertices * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 1; i <= vertices; i++) {
        if (graph->inDegree[i] == 0) { // 진입 차수가 0이면 push
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node *temp = graph->adjLists[current];
        while (temp != NULL) {
            int next = temp->vertex;
            graph->inDegree[next]--;
            if (graph->inDegree[next] == 0) { // 진입 차수가 0이 되면 (= 더 이상 next 노드로 오는 간선이 없으면) push
                queue[rear++] = next;
            }
            temp = temp->next;
        }
    }

    free(queue);
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    struct Graph *graph = createGraph(N+1);

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d%d", &A, &B);
        addEdge(graph, A, B);
        graph->inDegree[B]++; // 진입 차수 +1
    }

    topologicalSort(graph, N);

    // free graph
    for (int i = 1; i <= N; i++) {
        struct Node *temp = graph->adjLists[i];
        while (temp) {
            struct Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph->inDegree);
    free(graph);

    return 0;
}