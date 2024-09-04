#include <stdio.h>

int main() {
    int n, f[46] = {0, 1};
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) f[i] = f[i-1] + f[i-2];
    printf("%d", f[n]);
    
    return 0;
}