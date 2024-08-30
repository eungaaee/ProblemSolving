#include <stdio.h>

int main() {
    int N, ans = 1;
    scanf("%d", &N);
    while (N) ans *= N--;
    printf("%d", ans);
    return 0;
}