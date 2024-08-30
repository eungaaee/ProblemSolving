#include <stdio.h>

int main() {
    int N, ans = 1;
    scanf("%d", &N);
    while (N--) ans *= 2;
    printf("%d", ans);
    return 0;
}