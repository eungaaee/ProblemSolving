#include <stdio.h>

int main() {
    int n, cur, prev;
    unsigned long long W = 0, coin = 0;
    scanf("%d%llu", &n, &W);

    scanf("%d", &prev);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &cur);
        if (!coin && cur >= prev) {
            coin = W / prev;
            W %= prev;
        } else if (coin && cur < prev) {
            W += coin * prev;
            coin = 0;
        }
        prev = cur;
    }

    printf("%llu", W + coin*prev);
    return 0;
}