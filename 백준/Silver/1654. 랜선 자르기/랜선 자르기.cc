#include <malloc.h>

#include <algorithm>
#include <cstdio>
int main() {
    int k, n, *arr;
    long long t, amount, left, right, mid, max = 0, maxLength = 0;
    scanf("%d%d", &k, &n);
    arr = (int*)malloc(8 * k);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &t);
        arr[i] = t;
        max = t > max ? t : max;
    }
    std::sort(arr, arr + k);
    left = 1;
    right = max;
    while (left <= right) {
        mid = (left + right) / 2;
        amount = 0;
        for (int i = 0; i < k; i++) {
            amount += arr[i] / mid;
        }
        if (amount >= n) {  // mid가 기준보다 작아서 amount가 n보다 커져도 가능.
            maxLength = mid;
            left = mid + 1;
        } else if (amount < n) {
            right = mid - 1;
        }
    }
    printf("%lld", maxLength);
    free(arr);
    return 0;
}