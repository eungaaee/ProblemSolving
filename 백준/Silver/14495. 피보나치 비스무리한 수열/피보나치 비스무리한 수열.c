#include <stdio.h>

int main() {
    int n;
    long long f[117] = {0, 1, 1, 1};
    scanf("%d", &n);
    for (int i = 4; i <= n; i++) f[i] = f[i-1] + f[i-3];
    printf("%lld", f[n]);
    return 0;
}