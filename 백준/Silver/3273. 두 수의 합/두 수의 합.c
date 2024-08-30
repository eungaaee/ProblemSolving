#include <stdio.h>
#include <stdlib.h>

static inline int compare(int *a, int *b) { return *a - *b; }

int main() {
    int n, seq[100000], x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", seq+i);
    scanf("%d", &x);
    /* // 바닐라 퀵 소트로 하면 시간초과
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; j--) 
            if (seq[j-1] > seq[j]) seq[j-1] ^= seq[j], seq[j] ^= seq[j-1], seq[j-1] ^= seq[j]; */
    qsort(seq, n, 4, compare);
    int cnt = 0, l = 0, r = n-1;
    while (l < r) {
        if (seq[l] + seq[r] == x) cnt++, l++, r--;
        else if (seq[l] + seq[r] < x) l++;
        else r--;
    }
    printf("%d", cnt);
    return 0;
}