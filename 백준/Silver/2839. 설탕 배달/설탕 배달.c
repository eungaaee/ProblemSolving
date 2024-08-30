#include <stdio.h>
int main() {
    int n, f = 0, t = 0, c = 2000;
    scanf("%d", &n);
    for (int i = 0; i <= n / 5; i++) {
        for (int j = 0; j <= n / 3; j++) {
            if (i * 5 + j * 3 == n) {
                c = c < i + j ? c : i + j;
            }
        }
    }
    printf("%d", c==2000?-1:c);
    return 0;
}