#include <stdio.h>
#include <stdlib.h>

int N, C, house[200000];

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

_Bool is_possible(int distance) {
    int count = C-1;
    int prev = house[0];
    
    for (int i = 1; i < N; i++) {
        if (house[i] - prev >= distance) {
            count--;
            if (count == 0) return 1;
            else prev = house[i];
        }
    }

    return 0;
}

int main() {
    scanf("%d%d", &N, &C);

    for (int i = 0; i < N; i++) scanf("%d", house+i);
    qsort(house, N, sizeof(int), compare);

    // 공유기 사이의 가능한 최대 거리를 이분탐색
    int left = 1, right = house[N-1], mid;
    while (left <= right) {
        mid = (left+right) / 2;

        if (is_possible(mid)) left = mid+1;
        else right = mid-1;
    }

    printf("%d", right);

    return 0;
}