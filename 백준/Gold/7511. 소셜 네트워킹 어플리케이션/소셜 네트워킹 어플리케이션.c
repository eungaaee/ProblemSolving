#include <stdio.h>

int parent[1000000];

int Find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Unify(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x < y) parent[y] = x;
    else if (x > y) parent[x] = y;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int n, k;
        scanf("%d%d", &n, &k);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < k; i++) {
            int a, b;
            scanf("%d%d", &a, &b);

            if (Find(a) != Find(b)) Unify(a, b);
        }

        int m;
        scanf("%d", &m);
        printf("Scenario %d:\n", tc);

        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n", Find(u) == Find(v));
        }

        putchar('\n');
    }

    return 0;
}