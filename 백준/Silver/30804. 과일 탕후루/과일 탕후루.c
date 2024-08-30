#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int S[N];
    for (int i = 0; i < N; i++) scanf("%d", S+i);

    int nums[10] = {}, cnt = 0, max = 0, L = -1;
    for (int R = 0; R < N; R++) {
        if (nums[S[R]] == 0) cnt++;
        nums[S[R]]++;
        while (cnt > 2) {
            L++;
            nums[S[L]]--;
            if (nums[S[L]] == 0) cnt--;
        }
        if (R-L > max) max = R-L;
    }
    printf("%d", max);
    return 0;
}