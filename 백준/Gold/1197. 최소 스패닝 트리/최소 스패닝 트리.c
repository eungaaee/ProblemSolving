// 풀이1 - 크루스칼 알고리즘
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cost, A, B;
} cab;

int V, E;
cab *edge;
int *parent;

// Union Find
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]); // path compression
    return parent[x];
}

void makeUnion(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;
    else if (x < y) parent[y] = x;
    else parent[x] = y;
}

// compare func for qsort
int compare(const void *a, const void *b) {
    cab *A = (cab *)a;
    cab *B = (cab *)b;
    return A->cost - B->cost;
}

// Kruskal's Algorithm
int mst() {
    parent = (int *)malloc(V*4 + 4); // parent array for union find
    for (int i = 1; i <= V; i++) parent[i] = i;

    int weights = 0;
    for (int i = 0; i < E; i++) {
        if (find(edge[i].A) == find(edge[i].B)) continue; // if cycle occurs then skip

        weights += edge[i].cost; // if not then add cost to weights
        makeUnion(edge[i].A, edge[i].B); // update union
    }

    free(parent);
    return weights;
}

int main() {
    scanf("%d%d", &V, &E);

    edge = (cab *)malloc(E * sizeof(cab));
    for (int i = 0, A, B, C; i < E; i++) {
        scanf("%d%d%d", &A, &B, &C);

        edge[i] = (cab){C, A, B};
    }
    qsort(edge, E, sizeof(cab), compare);

    printf("%d", mst());

    free(edge);
    return 0;
}