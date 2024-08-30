#include <stdio.h>
#define MOD 1000000000

int main() {
    int n, f = 0, f1 = 1, f2;
    scanf("%d", &n);
    printf("%d\n", n>=0 ? n>0 : n%2 ? 1 : -1);
    if (n < 0) n = -n;
    for (int i = 0; i < n; i++) {
        f2 = f1;
        f1 = f;
        f = (f1+f2) % MOD;
    }
    printf("%d", f);
    return 0;
}