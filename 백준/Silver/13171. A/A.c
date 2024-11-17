#include <stdio.h>
#define MOD 1000000007

int square(long long base, long long n) {
    int res = 1;

    while (n > 0) {
        if (n & 1) res = (res * base) % MOD;
        
        base = (base * base) % MOD;
        n /= 2;
    }

    return res;
}

int main() {
    long long A, X;
    scanf("%lld%lld", &A, &X);

    printf("%d", square(A % MOD, X));

    return 0;
}