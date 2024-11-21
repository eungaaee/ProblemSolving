#include <stdio.h>

int main() {
    int N, K;
    scanf("%d%d", &N, &K);

    int multiplier = 1;
    for (int i = N; i > 0; i /= 10) {
        multiplier = (multiplier * 10) % K;
    }

    _Bool pigeonhole[K];
    for (int i = 1; i < K; i++) pigeonhole[i] = 0;

    int count = 0;
    int tmp = 0;

    while (1) {
        count++;
        tmp = ((long long)tmp * multiplier + N) % K;

        if (tmp == 0) { // 나누어 떨어지는 경우
            break;
        } else if (pigeonhole[tmp] == 1) { // 비둘기집 원리
            count = -1;
            break;
        } else {
            pigeonhole[tmp] = 1;
        }
    }

    printf("%d", count);

    return 0;
}