#include <stdio.h>

long long gcd(long long x, long long y) {
    if (x < y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }
    
    long long r;
    while (y > 0) {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

int main() {
    long long A, B;
    scanf("%lld%lld", &A, &B);

    int gcd_AB = gcd(A, B);
    while (gcd_AB--) putchar('1');

    return 0;
}