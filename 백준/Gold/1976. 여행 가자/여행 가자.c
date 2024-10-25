#include <stdio.h>

int parent[201];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void makeUnion(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
        return;
    else if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}

_Bool isUnion(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; i++) parent[i] = i;

    int isConnected;  // _Bool 에 scanf("%d") 사용 하면 제대로 동작 안 함
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &isConnected);
            if (isConnected) makeUnion(i, j);
        }
    }

    int i, prev, cur;
    scanf("%d", &prev);
    for (i = 1; i < M; i++) {
        scanf("%d", &cur);
        if (!isUnion(prev, cur)) break;
        else prev = cur;
    }
    printf("%s", i == M ? "YES" : "NO");

    return 0;
}