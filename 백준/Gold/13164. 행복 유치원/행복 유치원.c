// 가장 차이가 큰 곳에서부터 나눠버리기 <- 조의 개수-1 번 나눌 수 있으므로 차이가 큰 순으로 K-1개 제외시키기

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a; // less
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);

    int heights[N];
    for (int i = 0; i < N; i++) scanf("%d", heights+i);

    int diff[N-1];
    for (int i = 0; i < N-1; i++) diff[i] = heights[i+1]-heights[i];

    qsort(diff, N-1, sizeof(int), compare);

    int cost = 0;
    for (int i = K-1; i < N-1; i++) cost += diff[i];
    printf("%d", cost);

    return 0;
}