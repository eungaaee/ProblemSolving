#include <cstdio>
int main() {
    int n, x, k;
    scanf("%d", &n);
    if (n == 1) {
        printf("1");
        return 0;
    }
    x = n / 2;
    k = x;
    for (int i = 1; i <= n; i++) {
        printf("%d ", k);
        if (x == 1)
            k += 1;
        else {
            if (i % 2 || k - x - 1 == 0)
                k += x;
            else
                k -= x + 1;
        }
    }
    return 0;
}