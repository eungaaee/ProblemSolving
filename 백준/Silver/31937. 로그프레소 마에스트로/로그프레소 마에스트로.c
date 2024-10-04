#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
    int t, a, b;
} tab;

int compare(const void *a, const void *b) {
    tab *A = (tab *)a;
    tab *B = (tab *)b;
    return A->t - B->t;
}

int main() {
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);

    _Bool *infected = (_Bool *)calloc(N+1, 1);

    for (int i = 0, t; i < K; i++) {
        scanf("%d", &t);
        infected[t] = 1;
    }

    tab *log = (tab *)malloc(M * sizeof(tab));
    for (int i = 0; i < M; i++)
        scanf("%d%d%d", &log[i].t, &log[i].a, &log[i].b);

    qsort(log, M, sizeof(tab), compare);

    int cnt, origin;
    _Bool *virtualInfected = (_Bool *)malloc(N+1);

    for (int i = 1; i <= N; i++) { // 1-N까지 하나 씩 감염된 곳을 찾아서 시뮬레이션
        if (!infected[i]) continue; // 감염되지 않은 곳이면 continue

        memset(virtualInfected, 0, N+1);
        virtualInfected[i] = 1;
        cnt = 1;

        for (int j = 0, from, to; j < M; j++) {
            from = log[j].a;
            to = log[j].b;
            
            if (virtualInfected[from] & !infected[to]) break; // (시뮬레이션에서 감염 된 곳 -> 실제에서 감염되지 않은 곳) 인 경우는 안됨
            else if (virtualInfected[from] & !virtualInfected[to] & infected[from] & infected[to]) { // (시뮬레이션에서 감염된 곳 -> 시뮬레이션에서 감염되지 않은 곳) and (실제에서도 두 곳 모두 감염된 경우)
                virtualInfected[to] = 1;
                cnt++;
            }
        }

        if (cnt == K && (origin = i)) break;
    }

    printf("%d", origin);

    free(infected);
    free(log);
    free(virtualInfected);

    return 0;
}