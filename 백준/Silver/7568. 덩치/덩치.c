#include <stdio.h>
int main() {
    int n, dungchi[50][2], rank;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &dungchi[i][0], &dungchi[i][1]);
    }
    for (int i = 0; i < n; i++) {
        rank = 1;
        for (int j = 0; j < n; j++) {
            if (dungchi[i][0] < dungchi[j][0] && dungchi[i][1] < dungchi[j][1]) {
                rank++;
            }
        }
        printf("%d ", rank);
    }
    return 0;
}