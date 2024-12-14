#include <stdio.h>

int main() {
    int N, H;
    scanf("%d%d", &N, &H);

    int floor[H+1], ceil[H+1];
    for (int i = 0; i <= H; i++) floor[i] = ceil[i] = 0;

    for (int i = 0, x; i < N; i++) {
        scanf("%d", &x);

        if (i % 2) ceil[H-x + 1]++;
        else floor[x]++;
    }

    for (int i = 1; i <= H; i++) {
        floor[H-i] += floor[H-i + 1]; // for (i = H to 1) floor[i-1] += floor[i]
        ceil[i] += ceil[i-1];
    }

    int min = 1e9, count;
    for (int i = 1; i <= H; i++) {
        if (floor[i] + ceil[i] < min) {
            min = floor[i] + ceil[i];
            count = 1;
        } else if (floor[i] + ceil[i] == min) {
            count++;
        }
    }

    printf("%d %d", min, count);

    return 0;
}