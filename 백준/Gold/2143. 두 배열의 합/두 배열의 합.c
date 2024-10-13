// A, B에서 만들어 질 수 있는 부분 합들의 배열 만들기
// 정렬하고 이분탐색으로 합이 T인 경우의 수 세기
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int lower_bound(int *arr, int size, int target) {
    int l = 0, r = size, m, cnt = 0;
    while (l < r) {
        m = l + (r-l)/2;
        if (arr[m] < target) l = m+1;
        else r = m;
    }

    return l;
}

int upper_bound(int *arr, int size, int target) {
    int l = 0, r = size, m, cnt = 0;
    while (l < r) {
        m = l + (r-l)/2;
        if (arr[m] <= target) l = m+1;
        else r = m;
    }

    return l;
}

int main() {
    int T, n, m, *A, *B;

    // 입력
    scanf("%d", &T);

    scanf("%d", &n);
    A = (int *)malloc(n*4);
    for (int i = 0; i < n; i++) scanf("%d", A+i);

    scanf("%d", &m);
    B = (int *)malloc(m*4);
    for (int i = 0; i < m; i++) scanf("%d", B+i);

    // A의 부분합들의 배열 만들기
    int *partialsumA = (int *)malloc(n * (1+n) / 2 * sizeof(int));
    int psACnt = 0;

    for (int i = 0, sum; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j];
            partialsumA[psACnt++] = sum;
        }
    }

    // B의 부분합들의 배열 만들기
    int *partialsumB = (int *)malloc(m * (1+m) / 2 * sizeof(int));
    int psBCnt = 0;

    for (int i = 0, sum; i < m; i++) {
        sum = 0;
        for (int j = i; j < m; j++) {
            sum += B[j];
            partialsumB[psBCnt++] = sum;
        }
    }

    // 합이 T가 되는 경우의 수 세기
    qsort(partialsumB, psBCnt, 4, compare);
    long long cnt = 0; // MAXpsACnt * MAXpsBCnt = (1000 * (1+1000) / 2) ^ 2 = 500500^2 = 250500250000
    
    for (int i = 0; i < psACnt; i++) {
        // 부분합 A[i]를 기준으로 합이 T가 되는 B의 부분합 찾기
        int target = T - partialsumA[i];

        // 이분탐색 (upper_bound - lower_bound)
        int lower = lower_bound(partialsumB, psBCnt, target);
        int upper = upper_bound(partialsumB, psBCnt, target);

        // target을 찾지 못한 경우 lower upper 모두 배열의 끝을 가리키게 되므로 0이 된다
        cnt += upper - lower;
    }

    printf("%lld", cnt);

    free(A);
    free(B);
    free(partialsumA);
    free(partialsumB);

    return 0;
}