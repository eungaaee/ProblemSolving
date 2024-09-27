#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *liq;
    liq = (int *)malloc(4 * N);

    for (int i = 0; i < N; i++) scanf("%d", liq+i);

    int l = 0, r = N-1, minMix = 0x7fffffff, minL, minR;
    while (l < r) {
        int mix = liq[l] + liq[r], absMix = abs(mix);

        if (absMix < minMix) {
            minMix = absMix;
            minL = l;
            minR = r;
        }

        if (mix < 0) l++;
        else if (mix > 0) r--;
        else break;
    }

    printf("%d %d", liq[minL], liq[minR]);

    free(liq);
    return 0;
}