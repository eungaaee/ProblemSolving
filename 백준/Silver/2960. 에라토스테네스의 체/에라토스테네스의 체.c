#include <stdio.h>

int main() {
    int N, K;
    scanf("%d%d", &N, &K);

    _Bool isPrime[N+1];

    for (int i = 1; i <= N; i++) isPrime[i] = 1;
    isPrime[1] = 0;

    for (int i = 2; i <= N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i; j <= N; j += i) {
            if (!isPrime[j]) continue;
            isPrime[j] = 0;
            if (--K == 0) {
                printf("%d", j);
                return 0;
            }
        }
    }

    return 0;
}