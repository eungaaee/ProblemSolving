#include <stdio.h>

int toDec(int *k, int base, int kLen) {
    int dec = 0, mul = 1;
    for (int i = kLen-1; i >= 0; i--) {
        dec += k[i]*mul;
        mul *= base;
    }
    return dec;
}

void toN(int dec, int base) {
    if (!dec) return;
    toN(dec/base, base);
    printf("%d ", dec%base);
}

int main() {
    int A, B, m, N[25];
    scanf("%d%d%d", &A, &B, &m);
    for (int i = 0; i < m; i++) scanf("%d", N+i);
    toN(toDec(N, A, m), B);
}