#include <stdio.h>

void rec(int k) {
    if (k == 1 && putchar('-')) return;
    rec(k/3);
    for (int i = 0; i < k/3; i++) putchar(' ');
    rec(k/3);
}

int main() {
    int N, l;
    while (scanf("%d", &N) != EOF) {
        l = 1;
        while (N--) l *= 3;
        rec(l);
        putchar('\n');
    }
    return 0;
}