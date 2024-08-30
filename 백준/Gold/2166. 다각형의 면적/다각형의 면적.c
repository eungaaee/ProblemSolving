#include <stdio.h>

int main() {
    int N, prevx, prevy, x1, y1, x, y;
    long long exp1 = 0, exp2 = 0;
    scanf("%d", &N);
    scanf("%d%d", &x, &y);
    x1 = x, y1 = y;
    for (int i = 0; i < N-1; i++) {
        prevx = x, prevy = y;
        scanf("%d%d", &x, &y);
        exp1 += (long long)prevx*y, exp2 += (long long)x*prevy;
    }
    exp1 += (long long)x*y1, exp2 += (long long)x1*y;
    printf("%.1f", (exp1>exp2 ? exp1-exp2 : exp2-exp1)/2.0);
    return 0;
}