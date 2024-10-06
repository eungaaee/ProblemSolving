#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cost, A, B;
} cab;

int N, M, *parent;
cab *edge;

int compare(const void *a, const void *b) {
    cab *A = (cab *)a;
    cab *B = (cab *)b;
    return A->cost - B->cost;
}

// Union Find
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void makeUnion(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;
    else if (x < y) parent[y] = x;
    else parent[x] = y;
}

// Krukal's Algorithm
int mst() {
    parent = (int *)malloc(N*4 + 4);
    for (int i = 1; i <= N; i++) parent[i] = i;

    int weights = 0, largestCost = 0;

    for (int i = 0; i < M; i++) {
        if (find(edge[i].A) == find(edge[i].B)) continue; // if cycle occurs then skip

        makeUnion(edge[i].A, edge[i].B);
        weights += edge[i].cost;
        if (edge[i].cost > largestCost) largestCost = edge[i].cost;
    }

    free(parent);
    return weights - largestCost; // 최소 비용으로 마을을 두 개로 분할하기 위해 가장 큰 간선을 제거
}

int main() {
    scanf("%d%d", &N, &M);

    edge = (cab *)malloc(M * sizeof(cab));
    for (int i = 0, A, B, C; i < M; i++) {
        scanf("%d%d%d", &A, &B, &C);
        edge[i] = (cab){C, A, B};
    }
    qsort(edge, M, sizeof(cab), compare);

    printf("%d", mst());

    free(edge);
    return 0;
}