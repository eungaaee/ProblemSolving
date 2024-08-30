#include <stdio.h>
long long ink[500000], sticky[500000];
int main() {
    int n, left, right, mid;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &ink[i]);
    for (int i = 0; i < n; i++)
        scanf("%lld", &sticky[i]);
    for (int i = 0; i < n; i++) {
        left = 0;
        right = n;
        while (left < right) {
            mid = (left + right) / 2;
            if (sticky[mid] <= ink[i])
                left = mid + 1;
            else
                right = mid;
        }
        printf("%d ", right - i - 1);
    }
    return 0;
}