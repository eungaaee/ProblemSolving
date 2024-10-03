#include <stdio.h>

int parent[500001]; // 부모 노드를 저장하는 배열

int find(int n) {
    if (parent[n] == n) return n;
    return find(parent[n]);
}

void makeUnion(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;
    else if (x < y) parent[y] = x;
    else parent[x] = y; 
}

_Bool isUnion(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) parent[i] = i;

    int i, x, y;
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);

        if (isUnion(x, y)) break;
        makeUnion(x, y);
    }

    printf("%d", i <= m ? i : 0);

    return 0;
}