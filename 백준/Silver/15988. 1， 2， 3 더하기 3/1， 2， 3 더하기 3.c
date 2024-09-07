#include <stdio.h>

int way[1000001] = {[1] = 1, 2, 4};

int main() {
    int T, n;

    for (int i = 4; i <= 1000000; i++) way[i] = ((long long)way[i-1] + way[i-2] + way[i-3]) % 1000000009;

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", way[n]);
    }

    return 0;
}