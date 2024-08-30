#include <stdio.h>

int main() {
    int N, t, cnt = 0;
    _Bool pc[100] = {};
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &t);
        if (pc[t-1]) cnt++;
        else pc[t-1] = 1;
    }
    printf("%d", cnt);
    return 0;
}