#include <stdio.h>
#define min(a, b, c) (a < b ? a < c ? a : b < c ? b : c : b < c ? b : a < c ? a : c)

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int arr[n+1][m+1];
    for (int i = 0; i <= n; i++) arr[i][0] = 0;
    for (int i = 0; i <= m; i++) arr[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 0) continue;
            
            arr[i][j] = min(arr[i-1][j], arr[i][j-1], arr[i-1][j-1]) + 1;

            if (arr[i][j] > max) max = arr[i][j];
        }
    }

    printf("%d", max*max);

    return 0;
}