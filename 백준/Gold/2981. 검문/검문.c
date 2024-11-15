/*
A = M * q1 + r1
B = M * q2 + r2
r1 = A - M*q1
r2 = B - M*q2

r1 == r2:
A - M*q1 = B - M*q2
A-B = M * (q1-q2) = M * Q

(A-B) % M == 0

최대공약수를 구해서 약수들도 구하기
*/

#include <stdio.h>
#include <stdlib.h>

int get_gcd(int a, int b) {
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

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int N;
    scanf("%d", &N);

    int num[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", num+i);
    }
    qsort(num, N, sizeof(int), compare);

    // find gcd
    int gcd = num[1] - num[0];
    for (int i = 2; i < N; i++) {
        gcd = get_gcd(gcd, num[i] - num[i-1]);
    }

    // find all divisor
    int divisor[1000], divisor_idx = 0;

    for (int M = 2; M*M <= gcd; M++) {
        if (gcd % M == 0) {
            divisor[divisor_idx++] = M;
            if (M != gcd / M) divisor[divisor_idx++] = gcd / M;
        }
    }
    divisor[divisor_idx++] = gcd;

    qsort(divisor, divisor_idx, sizeof(int), compare);
    for (int i = 0; i < divisor_idx; i++) {
        printf("%d ", divisor[i]);
    }

    return 0;
}