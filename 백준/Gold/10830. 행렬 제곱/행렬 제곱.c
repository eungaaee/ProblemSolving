// 행렬 곱 개념 https://mathbang.net/562#gsc.tab=0
// 단위행렬 개념 https://mindole94.tistory.com/292
// -> A1[i][i] = 1이고 나머지는 0인 행렬에 임의의 행렬 A2를 곱하면 A2가 나온다.
#include <stdio.h>

int N;

void matrixMultiplier(int (*baseMatrix)[5], int (*multiplyMatrix)[5]) { // 행렬 곱
    int temp[5][5];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < N; k++) {
                temp[i][j] += baseMatrix[i][k] * multiplyMatrix[k][j];
            }
            temp[i][j] %= 1000;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            baseMatrix[i][j] = temp[i][j];
}

int main() {
    long long B;
    int A[5][5], nSquared[5][5];

    scanf("%d%lld", &N, &B);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", A[i]+j);
            nSquared[i][j] = 0;
        }
        nSquared[i][i] = 1; // 단위행렬로 만들기
    }

    while (B > 0) { // n^5 = (n^2)^2 * n
        if (B % 2) matrixMultiplier(nSquared, A); // nSquared *= A
        matrixMultiplier(A, A); // A *= A

        B /= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", nSquared[i][j]);
        putchar('\n');
    }

    return 0;
}