#include <stdio.h>

int main() {
    int T, n, f[46] = {0, 1}, ans[46], p = -1;
    for (int i = 2; i < 46; i++) f[i] = f[i - 1] + f[i - 2];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 45; n > 0; i--) {
            if (f[i] <= n) {
                n -= f[i];
                ans[++p] = f[i];
            }
        }
        for (; p >= 0; p--) printf("%d ", ans[p]);
        putchar('\n');
    }
    return 0;
}