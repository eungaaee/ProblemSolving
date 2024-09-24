/*
오름차순 rope[]에서 rope[0] * N, rope[1] * (N-1), ... , 중 최댓값이 정답
*/

#include <stdio.h>
#include <stdlib.h>

// 오름차순
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int N, *rope;

    scanf("%d", &N);

    rope = (int *)malloc(4 * N);
    for (int i = 0; i < N; i++) scanf("%d", rope+i);

    qsort(rope, N, 4, compare);

    int max = 0;
    for (int i = 0; i < N; i++)
        if (rope[i] * (N-i) > max) max = rope[i] * (N-i);

    printf("%d", max);

    free(rope);
    return 0;
}