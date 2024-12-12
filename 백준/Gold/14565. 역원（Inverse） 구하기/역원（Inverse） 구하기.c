#include <stdio.h>

long long gcd(long long a, long long b) {
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    long long r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long xgcd(long long a, long long b) {
    long long r1 = a, r2 = b;
    long long s1 = 1, s2 = 0;
    long long t1 = 0, t2 = 1;

    while (1) {
        long long q = r1 / r2;
        long long r = r1 - q*r2;
        long long s = s1 - q*s2;
        long long t = t1 - q*t2;

        if (r == 0) return s2;
        else {
            r1 = r2, r2 = r;
            s1 = s2, s2 = s;
            t1 = t2, t2 = t;
        }
    }
}

int main() {
    long long N, A;
    scanf("%lld%lld", &N, &A);

    long long add_inverse = N-A;
    long long multi_inverse;

    if (gcd(A, N) != 1) { // 서로소여야 곱셈 역원이 존재
        multi_inverse = -1;
    } else {
        multi_inverse = xgcd(A, N);
        if (multi_inverse < 0) multi_inverse = N + multi_inverse;
    }

    printf("%lld %lld", add_inverse, multi_inverse);

    return 0;
}