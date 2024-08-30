#include <stdio.h>

int factElement(int k, int x) {
    int cnt = 0;
    for (long long i = x; k/i > 0; i *= x) cnt += k/i;
    return cnt;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    long long two, five;
    two = (long long)factElement(n, 2) - factElement(n-m, 2) - factElement(m, 2);
    five = (long long)factElement(n, 5) - factElement(n-m, 5) - factElement(m, 5);
    printf("%lld", two < five ? two : five);
    
    return 0;
}