// 피사노 주기
#include <stdio.h>
#define cycle (15 * 100000) // 15 * 10^(6-1);

int F[cycle];

int main() {
    long long n;
    scanf("%lld", &n);

    F[0] = 0, F[1] = 1;
    for (int i = 2; i < cycle; i++)
        F[i] = (F[i-1] + F[i-2]) % 1000000;
    
    printf("%d", F[n%cycle]);

    return 0;
}