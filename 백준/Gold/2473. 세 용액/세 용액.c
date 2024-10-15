#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

static inline unsigned int longAbs(long long a) {
    return a < 0 ? -a : a;
}

int main() {
    int N;
    scanf("%d", &N);

    int *liq = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) scanf("%d", liq+i);

    qsort(liq, N, sizeof(int), compare);

    struct minLiquid {
        unsigned int spec;
        int a, b, c;
    } minLiquid;
    minLiquid.spec = 0xffffffff;

    for (int i = 0; i < N; i++) {
        int l = i+1, r = N-1;
        while (l < r) {
            long long mixed = (long long)liq[i] + liq[l] + liq[r];
            if (longAbs(mixed) < minLiquid.spec) { // *알게된 것: <stdlib.h> abs()는 int형 함수이다. 이런 젠장
                minLiquid = (struct minLiquid){longAbs(mixed), liq[i], liq[l], liq[r]};
            }

            if (mixed < 0) l++;
            else r--;
        }
    }

    printf("%d %d %d", minLiquid.a, minLiquid.b, minLiquid.c);

    free(liq);
    return 0;
}