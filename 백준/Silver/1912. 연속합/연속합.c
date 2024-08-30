#include <stdio.h>

int main() {
    int n, seq[100001], max = -1000;
    scanf("%d", &n);
    seq[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", seq+i);
        if (seq[i-1] + seq[i] > seq[i]) seq[i] = seq[i-1] + seq[i];
        if (seq[i] > max) max = seq[i];
    }
    printf("%d", max);
    return 0;
}