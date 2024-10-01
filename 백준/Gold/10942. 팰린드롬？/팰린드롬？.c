/*
길이 1: palindrome[i][i] = 1
길이 2: palindrome[i][i+1] = (arr[i] == arr[i+1]) 이면 1
길이 3+: palindrome[i+1][j-1] == 1 이고 arr[i] == arr[j] 이면 1
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, *arr, M;
    scanf("%d", &N);

    // 칠판
    arr = (int *)malloc(4*N + 4);
    for (int i = 1; i <= N; i++) scanf("%d", arr+i);

    // dp배열 동적할당
    _Bool **p = (_Bool **)malloc(8*N + 8);
    for (int i = 1; i <= N; i++) p[i] = (_Bool *)calloc(N+1, 1);

    // palindrome[i][i] = 1
    for (int i = 1; i <= N; i++) p[i][i] = 1;

    // palindrome[i-1][i] = 1 if arr[i-1] == arr[i]
    for (int i = 2; i <= N; i++)
        if (arr[i-1] == arr[i]) p[i-1][i] = 1;

    // palindrome[i][j] = 1 if palindrome[i+1][j-1] == 1 && arr[i] == arr[j]
    for (int i = N-2; i >= 1; i--) {
        for (int j = i+2; j <= N; j++) {
            if (p[i+1][j-1] && arr[i] == arr[j]) p[i][j] = 1;
        }
    }

    // Questions
    scanf("%d", &M);
    while (M--) {
        int S, E;
        scanf("%d%d", &S, &E);

        printf("%d\n", p[S][E]);
    }

    for (int i = 1; i <= N; i++) free(p[i]);
    free(p);
    free(arr);

    return 0;
}