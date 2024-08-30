#include <stdio.h>

int parent[1000001];

int find(int n) {
    if (parent[n] == n) return n;
    else return parent[n] = find(parent[n]);
}

void unify(int a, int b) {
    int aRoot = find(a), bRoot = find(b);
    if (aRoot == bRoot) return;
    else parent[bRoot] = aRoot;
}

int main() {
    for(int i = 0; i <= 1000000; i++) parent[i] = i;
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d%d", &c, &a, &b);
        if (c) printf(find(a) == find(b) ? "YES\n" : "NO\n");
        else unify(a, b);
    }
    return 0;
}