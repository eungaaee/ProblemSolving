#include <stdio.h>

int main() {
    int N, S, M, V[51];
    
    scanf("%d%d%d", &N, &S, &M);
    for (int i = 1; i <= N; i++) scanf("%d", V+i);

    int prev[1001], cur[1001];
    for (int i = 0; i <= M; i++) prev[i] = -1;
    prev[S] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) cur[j] = -1;

        for (int P = 0; P <= M; P++) {
            if (prev[P] == i-1) {
                if (P-V[i] >= 0) cur[P-V[i]] = i;
                if (P+V[i] <= M) cur[P+V[i]] = i;
            }
        }
        
        for (int j = 0; j <= M; j++) {
            if (cur[j] == -1) continue;
            prev[j] = cur[j];
        }
    }

    int ans = -1;
    for (int i = M; i >= 0; i--) {
        if (prev[i] == N) {
            ans = i;
            break;
        }
    }

    printf("%d", ans);

    return 0;
}