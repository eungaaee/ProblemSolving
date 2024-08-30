#include <cstdio>

int main() {
    int N;
    scanf("%d", &N);

    long long f[3], ans;
    f[0] = f[1] = 1;
    for (int i = 2; i < N; i++) {
        f[2] = f[1] + f[0];
        f[0] = f[1], f[1] = f[2];
    }
    if (N == 1) ans = 4;
    else ans = f[1]*4 + f[0]*2;
    printf("%lld", ans);
    return 0;
}