#include <stdio.h>

long long nCr(long long n, int r) {
    if (n < r) return 0;

    long long up = 1, down = 1;
    for (int i = 0; i < r; i++) up *= (n-i);
    for (int i = 2; i <= r; i++) down *= i;
    return up/down;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    int S[N+1];
    S[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", S+i);
        S[i] = (S[i-1] % M + S[i] % M) % M;
    }

    long long R[M]; // R[i] = 나머지가 i인 경우의 수 count
    for (int i = 0; i < M; i++) R[i] = 0;
    for (int i = 1; i <= N; i++) R[S[i]]++;

    long long ans = R[0]; // 그냥 0부터 n까지의 구간합이 0이었던 경우들을 더해주기
    for (int i = 0; i < M; i++)
        ans += nCr(R[i], 2); // 두 구간합의 나머지가 같은 경우 == 부분 구간의 합의 나머지가 0. 나머지가 같은것들 중 2개를 고르는 경우의 수를 더하기

    printf("%lld", ans);

    return 0;
}