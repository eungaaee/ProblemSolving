#include <stdio.h>

int parent[51];

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) return;
    else if (x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; i++) parent[i] = i;

    int knowCnt, t;
    scanf("%d", &knowCnt);
    for (int i = 0; i < knowCnt; i++) {
        scanf("%d", &t);
        parent[t] = 0;
    }

    int party[51][51] = {};
    for (int i = 0; i < M; i++) {
        int participantCnt;
        scanf("%d", &participantCnt);
        for (int j = 0; j < participantCnt; j++) {
            scanf("%d", &party[i][j]); // *(party+i)+j
            if (j > 0) Union(party[i][j-1], party[i][j]);
        }
    }

    int ans = M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; party[i][j] > 0; j++) {
            if (Find(party[i][j]) == 0) {
                ans--;
                break;
            }
        }
    }

    printf("%d", ans);

    return 0;
}