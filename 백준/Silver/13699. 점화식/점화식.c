#include <stdio.h>

int main() {
    int n;
    unsigned long long t[36] = {1};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            t[i] += t[j] * t[i-1-j];
        }
    }
    printf("%lld", t[n]);
    return 0;
}