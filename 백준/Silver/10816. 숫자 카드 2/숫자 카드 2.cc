#include <algorithm>
#include <cstdio>
int lowerBound(int n, int narr[], int k) {
    int left = 0, right = n+1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        k <= narr[mid] ? right = mid : (left = mid + 1);
    }
    return right;
}
int upperBound(int n, int narr[], int k) {
    int left = 0, right = n+1, mid;
    while (left < right) {
        mid = (left + right) / 2;
        k < narr[mid] ? right = mid : (left = mid + 1);
    }
    return right;
}
int main() {
    int n, m, mnum;
    scanf("%d", &n);
    int narr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &narr[i]);
    }
    std::sort(narr, narr + n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &mnum);
        printf("%d ", upperBound(n - 1, narr, mnum) - lowerBound(n - 1, narr, mnum));
    }
    return 0;
}