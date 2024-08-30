#include <stdio.h>

static inline int abs(int n) {
    if (n < 0) return -n;
    else return n;
}

int main() {
    int a, b, c, d, t, cnt;
    while (1) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (a+b+c+d == 0) break;
        cnt = 0;
        while (1) {
            if (a==b && b==c && c==d) break;
            cnt++;
            t = a;
            a = abs(a-b), b = abs(b-c), c = abs(c-d), d = abs(d-t);
        }
        printf("%d\n", cnt);
    }
    return 0;
}