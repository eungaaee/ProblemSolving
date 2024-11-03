#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int lower_bound(int *arr, int size, int target) {
    int l = 0, r = size-1, m;

    while (l < r) {
        m = l+r>>1;
        if (arr[m] < target) l = m+1;
        else r = m;
    }

    return l;
}

int upper_bound(int *arr, int size, int target) {
    int l = 0, r = size-1, m;
    
    while (l < r) {
        m = l+r>>1;
        if (arr[m] <= target) l = m+1;
        else r = m;
    }

    return l;
}

static inline _Bool isDuplicated(int i, int j, int lower, int upper) {
    if (upper-lower == 1 && ((lower <= i && i < upper) || (lower <= j && j < upper))) return 1;
    else if (upper-lower == 2 && ((lower <= i && i < upper) && (lower <= j && j < upper))) return 1;
    else return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) scanf("%d", A+i);

    qsort(A, N, sizeof(int), compare);

    int ans = 0;

    // 풀이1 - 피벗 이분탐색. A[j]를 피벗으로, A[j]와의 합이 A[i]인 값을 찾기
    /* for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int target = A[i] - A[j];

            // target이 존재하면 A[i]가 좋은 수 이므로 ans++하고 다음 A[i] 검사
            int lower = lower_bound(A, N, target);
            int upper = upper_bound(A, N, target);
            
            if (upper-lower > 0 && !isDuplicated(i, j, lower, upper)) {
                ans++;
                break;
            }
        }
    } */

    // 풀이2 - 투포인터
    for (int i = 0; i < N; i++) {
        int l = 0, r = N-1, target = A[i];

        while (l < r) {
            if (l == i && ++l) continue;
            else if (r == i && r--) continue;

            int cur = A[l] + A[r];
            
            if (cur < target) l++;
            else if (cur > target) r--;
            else if (++ans) break;
        }
    }

    printf("%d", ans);

    return 0;
}