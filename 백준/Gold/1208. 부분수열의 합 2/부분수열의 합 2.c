/*
arr을 반으로 나눠서 생각
왼쪽에서 만들어지는 부분수열들의 원소 합 배열과
오른쪽에서 만들어지는 부분수열들의 원소 합 배열을 만들고
왼쪽 원소 합 배열을 돌면서 이분탐색으로 그에 맞는 오른쪽 원소 합 배열의 원소 개수 구하기 
*/
#include <stdio.h>
#include <stdlib.h>

int N, S;
int arr[40], leftSums[1<<20], rightSums[1<<20], lIdx, rIdx;

void getLeft(int idx, int sum) {
    if (idx == N/2) {
        leftSums[lIdx++] = sum;
        return;
    }

    getLeft(idx+1, sum); // 현재 원소를 포함하지 않는 경우
    getLeft(idx+1, sum+arr[idx]); // 현재 원소를 포함하는 경우
}

void getRight(int idx, int sum) {
    if (idx == N) {
        rightSums[rIdx++] = sum;
        return;
    }

    getRight(idx+1, sum);
    getRight(idx+1, sum+arr[idx]);
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int upper_bound(int *arr, int target) {
    int l = 0, r = rIdx, m;
    while (l < r) {
        m = l + (r-l)/2;
        if (arr[m] <= target) l = m+1;
        else r = m;
    }

    return l;
}

int lower_bound(int *arr, int target) {
    int l = 0, r = rIdx, m;
    while (l < r) {
        m = l + (r-l)/2;
        if (arr[m] < target) l = m+1;
        else r = m;
    }

    return l;
}

int main() {
    scanf("%d%d", &N, &S);

    for (int i = 0; i < N; i++) {
        scanf("%d", arr+i);
    }

    getLeft(0, 0);
    getRight(N/2, 0);

    qsort(rightSums, rIdx, sizeof(int), compare);

    long long ans = 0;
    for (int i = 0; i < lIdx; i++) {
        int target = S - leftSums[i];
        ans += upper_bound(rightSums, target) - lower_bound(rightSums, target);
    }

    if (S == 0) ans--; // S = 0이면 왼쪽 오른쪽 둘 다 아무것도 포함하지 않는 경우가 포함되어버리므로
    printf("%lld", ans);

    return 0;
}