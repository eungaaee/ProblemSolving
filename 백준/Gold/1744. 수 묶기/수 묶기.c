#include <stdio.h>
#include <stdlib.h>

int less(void *a, void *b) { // 오름차순
    if (*(int*)a < *(int*)b) return -1;
    else if (*(int*)a > *(int*)b) return 1;
    else return 0;
}

int greater(void *a, void *b) { // 내림차순
    if (*(int*)a < *(int*)b) return 1;
    else if (*(int*)a > *(int*)b) return -1;
    else return 0;
}

int main() {
    int N, pseq[50], nseq[50], pp = 0, np = 0, ans = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", pseq+pp++);
        if (pseq[pp-1] == 1) ans += 1, pp--; // 1은 곱하지 말고 더하기
        else if (pseq[pp-1] <= 0) nseq[np++] = pseq[--pp]; // 음수 수열에 0 넣어서 줄이기
    }

    qsort(pseq, pp, 4, greater);
    qsort(nseq, np, 4, less);

    for (int i = 1; i < pp; i+=2) ans += pseq[i-1]*pseq[i];
    if (pp % 2) ans += pseq[pp-1];

    for (int i = 1; i < np; i+=2) ans += nseq[i-1]*nseq[i];
    if (np % 2) ans += nseq[np-1];

    printf("%d", ans);

    return 0;
}