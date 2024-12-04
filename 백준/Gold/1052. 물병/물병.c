#include <stdio.h>

int CountBits(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) count++;
        n >>= 1;
    }
    return count;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);

    int i = 0;
    while (CountBits(N+i) > K) i++;
    printf("%d", i);

    return 0;
}