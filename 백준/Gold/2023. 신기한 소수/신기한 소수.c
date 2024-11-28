#include <stdio.h>

_Bool is_prime(int n) {
    if (n == 1) return 0;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }

    return 1;
}

void backtrack(int n, int digit) {
    if (digit == 0) {
        printf("%d\n", n);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (is_prime(n*10 + i)) {
            backtrack(n*10 + i, digit-1);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    backtrack(0, N);

    return 0;
}