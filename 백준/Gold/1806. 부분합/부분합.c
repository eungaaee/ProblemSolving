#include <stdio.h>
#include <stdlib.h>

const int INF = 0x7fffffff;

int main() {
    int N, S, *arr;
    scanf("%d%d", &N, &S);

    arr = (int *)malloc(4 * N);
    for (int i = 0; i < N; i++) scanf("%d", arr+i);

    int l = 0, r = 0, partialSum = arr[0], minLen = INF;
    while (l <= r) {
        if (partialSum < S) {
            if (r == N-1) break;
            partialSum += arr[++r];
        } else {
            if (r-l+1 < minLen) minLen = r-l+1;
            partialSum -= arr[l++];
        }
    }

    printf("%d", minLen < INF ? minLen : 0);

    free(arr);
    return 0;
}