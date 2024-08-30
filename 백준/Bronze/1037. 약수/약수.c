#include <stdio.h>

int main() {
    int N, t, min = 0x3f3f3f3f, max = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &t);
        if (min > t) min = t;
        if (max < t) max = t;
    }
    printf("%d", min*max);
    return 0;
}