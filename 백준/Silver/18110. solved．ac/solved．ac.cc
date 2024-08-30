#include <malloc.h>
#include <algorithm>
#include <cstdio>
int main() {
    int n, *arr, cut, summary{0};
    scanf("%d", &n);
    if (n == 0) {
        puts("0");
        return 0;
    }
    arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr + n);
    cut = (double)n * 15 / 100 - (double)(n * 15 / 100) >= 0.5 ? n * 15 / 100 + 1 : n * 15 / 100;
    for (int i = cut; i < n - cut; i++) {  // 9, n==10, cut==3, (012)3456(789)
        summary += arr[i];
    }
    summary = (double)summary / (n - cut * 2) - (double)(summary / (n - cut * 2)) >= 0.5 ? summary / (n - cut * 2) + 1 : summary / (n - cut * 2);
    printf("%d", summary);
    free(arr);
    return 0;
}