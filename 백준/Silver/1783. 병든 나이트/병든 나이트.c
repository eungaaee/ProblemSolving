#include <stdio.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    int ans;
    if (N == 1) ans = 1;
    else if (N == 2) {
        ans = (M-1)/2 + 1;
        if (ans > 4) ans = 4;
    } else if (N > 2) {
        if (M < 7) ans = M < 4 ? M : 4;
        else ans = M-2;
    }
    printf("%d", ans);

    return 0;
}