#include <stdio.h>
#define abs(n) (n) < 0 ? -(n) : (n)

int gcd(int a, int b) {
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    int r;
    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int N, S;
    scanf("%d%d", &N, &S);

    int A[N];

    for (int i = 0, t; i < N; i++) {
        scanf("%d", &t);
        A[i] = abs(S-t);
    }

    int D = A[0];
    for (int i = 1; i < N; i++) {
        D = gcd(D, A[i]);
    }
    printf("%d", D);

    return 0;
}