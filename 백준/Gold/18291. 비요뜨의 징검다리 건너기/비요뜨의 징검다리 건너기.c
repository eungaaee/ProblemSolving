#include <stdio.h>
#define MOD 1000000007

int square(int base, int n) {
    int res = 1;

    while (n > 0) {
        if (n % 2) res = ((long long)res * base) % MOD;

        base = ((long long)base * base) % MOD;
        n /= 2;
    }

    return res;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);
        printf("%d\n", N >= 2 ? square(2, N-2) : 1);
    }

    return 0;
}