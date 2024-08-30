#include <stdio.h>
int a, b, c;
long long f(int localb) {
    if (localb == 1)
        return a % c;
    long long k = f(localb / 2) % c;
    if (localb % 2)
        return k * k % c * a % c;
    else
        return k * k % c;
}
int main() {
    scanf("%d%d%d", &a, &b, &c);
    printf("%lld", f(b));
    return 0;
}