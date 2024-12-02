#include <stdio.h>

int main() {
    int H, W;
    scanf("%d%d", &H, &W);

    int block[W];
    for (int i = 0; i < W; i++) scanf("%d", block+i);

    int ans = 0;

    for (int i = 1; i < W-1; i++) {
        int left_max = block[i-1];
        for (int j = i-2; j >= 0; j--) {
            if (block[j] > left_max)
                left_max = block[j];
        }

        int right_max = block[i+1];
        for (int j = i+2; j <= W-1; j++) {
            if (block[j] > right_max)
                right_max = block[j];
        }

        if (left_max <= block[i] || right_max <= block[i]) continue;
        ans += (left_max < right_max ? left_max : right_max) - block[i];
    }

    printf("%d", ans);

    return 0;
}