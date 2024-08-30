#include <stdio.h>
int main() {
    int a, k, c = 0;
    scanf("%d%d", &a, &k);
    while (k / a >= 2) {
        if (k % 2)
            k -= 1;
        else
            k /= 2;
        c++;
    }
    c += k - a;
    printf("%d", c);
}