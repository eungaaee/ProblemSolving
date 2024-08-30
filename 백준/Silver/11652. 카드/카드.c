#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long n1 = *(long long *)a;
    long long n2 = *(long long *)b;
    if (n1 < n2) return -1;
    else if (n1 > n2) return 1;
    else return 0;
}

int main() {
    int N;
    long long C[100000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%lld", C+i);

    qsort(C, N, 8, compare);

    int cnt = 0, maxCnt = 0;
    long long maxNum = C[0];
    for (int i = 1; i < N; i++) {
        if (C[i-1] == C[i]) cnt++;
        else cnt = 0;

        if (cnt > maxCnt) maxCnt = cnt, maxNum = C[i-1];
    }
    printf("%lld", maxNum);
    return 0;
}