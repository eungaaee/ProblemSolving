#include <stdio.h>
#define MOD 1000000000

int main() {
    int N, arr[100][10];
    scanf("%d", &N);
    arr[0][0] = 0;
    for (int i = 1; i < 10; i++) arr[0][i] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) arr[i][0] = arr[i-1][1];
            else if (j == 9) arr[i][9] = arr[i-1][8];
            else arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % MOD;
        }
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) sum = (sum + arr[N-1][i]) % MOD;
    printf("%d", sum);
    return 0;
}