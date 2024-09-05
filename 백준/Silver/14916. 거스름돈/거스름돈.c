#include <stdio.h>

int main() {
    int n, coin[100001];

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) coin[i] = 0x7fffffff;
    coin[2] = coin[5] = 1;

    for (int i = 3; i <= n; i++) {
        if (i-2 >= 0 && coin[i-2] < 0x7fffffff && coin[i-2] + 1 < coin[i]) coin[i] = coin[i-2] + 1;
        if (i-5 >= 0 && coin[i-5] < 0x7fffffff && coin[i-5] + 1 < coin[i]) coin[i] = coin[i-5] + 1;
    }

    if (coin[n] < 0x7fffffff) printf("%d", coin[n]);
    else printf("-1");

    return 0;
}