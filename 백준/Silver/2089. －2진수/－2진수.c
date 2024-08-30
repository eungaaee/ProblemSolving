#include <stdio.h>

void stack(int k) {
    if (!k) return;
    if (k % -2) {
        stack((k-1) / -2);
        putchar('1');
    } else {
        stack(k / -2);
        putchar('0');
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    if (!N) putchar('0');
    else stack(N);

    return 0;
}