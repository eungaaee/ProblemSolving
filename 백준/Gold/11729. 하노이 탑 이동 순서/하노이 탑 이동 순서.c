// a(n) = 2*a(n-1) + 1
#include <stdio.h>

void hanoi(int from, int via, int to, int n) {
    if (n == 1) printf("%d %d\n", from, to);
    else {
        hanoi(from, to, via, n-1);
        printf("%d %d\n", from, to);
        hanoi(via, from, to, n-1);
    }
}

int main() {
    int N, cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) cnt = cnt*2 + 1;
    printf("%d\n", cnt);
    hanoi(1, 2, 3, N);
    return 0;
}