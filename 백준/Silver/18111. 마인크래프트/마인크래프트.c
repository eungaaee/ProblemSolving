#include <malloc.h>
#include <stdio.h>
int main() {
    int n, m, b, mint = 200000000, *arr, yBlocks, minedBlocks, usedBlocks;
    scanf("%d%d%d", &n, &m, &b);
    arr = (int*)malloc(4 * n * m);
    for (int i = 0; i < n * m; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i <= 256; i++) {
        minedBlocks = 0;
        usedBlocks = 0;
        for (int j = 0; j < n * m; j++) {
            if (i < arr[j]) {
                minedBlocks += arr[j] - i;
            } else if (i > arr[j]) {
                usedBlocks += i - arr[j];
            }
        }
        if (usedBlocks <= minedBlocks + b) {
            if (minedBlocks * 2 + usedBlocks <= mint) {
                mint = minedBlocks * 2 + usedBlocks;
                yBlocks = i;
            }
        }
    }
    printf("%d %d", mint, yBlocks);
    free(arr);
    return 0;
}