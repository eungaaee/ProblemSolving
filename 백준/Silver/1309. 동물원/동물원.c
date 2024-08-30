// 1, 3, 7, 17, 41 -> 2*A(N-1) + A(N-2)
#include <stdio.h>

int main() {
    int N, lion[100001] = {1, 3};
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) lion[i] = (2*lion[i-1]+lion[i-2])%9901;
    printf("%d", lion[N]);
    return 0;
}