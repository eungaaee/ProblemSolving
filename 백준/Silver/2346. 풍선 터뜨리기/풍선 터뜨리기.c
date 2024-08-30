#include <stdio.h>

int main() {
    int N, balloons[1001];
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", balloons+i);
    
    int p, prev_p, prev_v;
    p = 0, balloons[p] = 1;
    for (int i = 0; i < N; i++) {
        prev_p = p, prev_v = balloons[prev_p];
        balloons[prev_p] = 0;
        while (prev_v) {
            do {
                prev_v > 0 ? p++ : p--;
                if (p < 1) p = N;
                else if (p > N) p = 1;
            } while (balloons[p] == 0);
            prev_v > 0 ? prev_v-- : prev_v++;
        }
        printf("%d ", p);
    }
    return 0;
}