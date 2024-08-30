#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, P[1001] = {};
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) scanf("%d", P+i);

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            int prev, cur = i;
            if (!P[cur]) continue;
            while (1) {
                prev = cur;
                cur = P[cur];
                P[prev] = 0;
                if (!P[cur]) {
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}