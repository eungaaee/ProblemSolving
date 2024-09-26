/*
b^(-1) mod x = b^(x-2)

정수가 될 때:
그냥 a/b 출력

기약분수가 될 떄:
x = 1,000,000,007

(a * b^(-1)) mod x
= (a * b^(x-2)) mod x

a * b^(x-2) mod 1,000,000,007 출력
*/

#include <stdio.h>

const int MOD = 1000000007;

int gcd(int x, int y) {
    if (x < y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }
    // x > y

    int r;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

long long pow(int x, int n) {
    // x^n
    if (n == 1) return x;
    else if (n % 2) return x * pow(x, n-1) % MOD;

    long long half = pow(x, n/2) % MOD;
    return half * half % MOD;
}

int main() {
    int M, N, S;
    scanf("%d", &M);

    int ans = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &N, &S);

        int curGCD = gcd(N, S);
        N /= curGCD;
        S /= curGCD;

        ans += S * pow(N, MOD-2) % MOD;
        ans %= MOD;
    }

    printf("%d", ans);
    return 0;
}