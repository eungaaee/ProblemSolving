/*
0000
0001

0010
0011

0100
0101
0110
0111

1000
1001
1010
1011
1100
1101
1110
1111

n = MSB's position, n >= 0
prefix_sum[n] = prefix_sum[n-1] + prefix_sum[n-1](= MSB 제외한 뒤의 숫자들이 누적되어 반복되므로) + MSB들(= 2^n)

for i = 54 to 1
    if n & (1<<i)
        n -= 2^i
        ans += prefix_sum[i-1] + n+1
*/
#include <stdio.h>

long long moongtaeng_prefix_sum[55] = {[0] = 1};

long long get_prefix_sum(long long n) {
    long long res = n&1;

    for (int i = 54; i > 0; i--) {
        if (n & (1LL<<i)) {
            n -= 1LL<<i;
            res += moongtaeng_prefix_sum[i-1] + n+1;
        }
    }

    return res;
}

int main() {
    long long A, B;
    scanf("%lld%lld", &A, &B);

    for (int i = 1; i < 55; i++)
        moongtaeng_prefix_sum[i] = moongtaeng_prefix_sum[i-1] * 2 + (1LL<<i);

    printf("%lld", get_prefix_sum(B) - get_prefix_sum(A-1));

    return 0;
}