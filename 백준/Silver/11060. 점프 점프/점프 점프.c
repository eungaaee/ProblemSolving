#include <stdio.h>
#define INF 0x3f3f3f3f

int main() {
    int N, A, jump[1000];
    scanf("%d", &N);
    jump[0] = 0;
    for (int i = 1; i < N; i++) jump[i] = INF;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A);
        for (int j = 1; j <= A; j++)
            if (i+j < N && jump[i]+1 < jump[i+j]) jump[i+j] = jump[i]+1;
    }
    printf("%d", jump[N-1] < INF ? jump[N-1] : -1);
    return 0;
}