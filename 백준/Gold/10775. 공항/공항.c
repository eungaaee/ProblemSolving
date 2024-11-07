#include <stdio.h>

int parent[100000];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void make_union(int x, int y) {
    x = find(x);
    y = find(y);

    if (x > y) x^=y, y^=x, x^=y; // 더 작은 숫자를 부모로
    parent[y] = x;
}

int main() {
    int G, P;
    scanf("%d%d", &G, &P);

    for (int i = 1; i <= G; i++) parent[i] = i;

    int ans = 0;
    for (int i = 0, g; i < P; i++) {
        scanf("%d", &g);

        g = find(g);
        if (g > 0) {
            make_union(g-1, g); // 이제 g는 못 사용하도록 g-1로 연결시키기
            ans++;
        } else break;
    }

    printf("%d", ans);

    return 0;
}