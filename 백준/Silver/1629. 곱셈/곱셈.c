#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);

    int ans = 1;
    while (B > 0) {
        if (B % 2) ans = ((long long)ans * A) % C;
        A = ((long long)A*A) % C;
        B /= 2;
    }
    printf("%d", ans);

    return 0;
}