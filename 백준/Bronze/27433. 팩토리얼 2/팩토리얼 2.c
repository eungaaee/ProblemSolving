#include <stdio.h>

long long f(long long n) {
    if (n <= 1) return 1;
    return n * f(n-1);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%lld", f(N));
    return 0;
}