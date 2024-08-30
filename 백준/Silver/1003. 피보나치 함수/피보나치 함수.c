#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibonacci(int n);

int main() {
    int t, n;

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        fibonacci(n);
    }
    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        printf("%d %d\n", 1, 0);
        return 0;
    }
    else if (n == 1) {
        printf("%d %d\n", 0, 1);
        return 0;
    }
    int count0 = 1;
    int count1 = 0;
    int ncount0 = 0;
    int ncount1 = 1;
    int temp0, temp1;

    for (int i = 0; i < n-1; i++) {
        temp0 = ncount0;
        temp1 = ncount1;
        ncount0 += count0;
        ncount1 += count1;
        count0 = temp0;
        count1 = temp1;
    }
    printf("%d %d\n", ncount0, ncount1);
}