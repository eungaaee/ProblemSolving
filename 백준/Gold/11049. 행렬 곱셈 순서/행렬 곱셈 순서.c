#include <stdio.h>
#define INF 0x7fffffff

int main() {
    int N;
    scanf("%d", &N);

    struct {
        int r, c;
    } matrix[N];

    for (int i = 0; i < N; i++) scanf("%d%d", &matrix[i].r, &matrix[i].c);

    int AtoB[500][500] = {}; // AtoB[i][j] = i~j번째 행렬까지 곱할 때의 최소 연산 횟수

/*     // i to j
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            AtoB[i][j] = INF;
            for (int k = i; k < j; k++) {
                // 행렬 i~k 연산 횟수 + 양쪽 두 행렬을 곱할 때 연산하는 횟수 + 행렬k+1~j 연산 횟수
                int temp = AtoB[i][k] + matrix[i].r * matrix[k].c * matrix[j].c + AtoB[k+1][j];
                if (temp < AtoB[i][j]) AtoB[i][j] = temp;
            }
        }
    } */

    // i to j
    for (int len = 1; len < N; len++) { // 곱할 행렬의 개수
        for (int i = 0; i+len < N; i++) {
            AtoB[i][i+len] = INF;
            for (int k = i; k < i+len; k++) {
                // 행렬 i~k 연산 횟수 + 양쪽 두 행렬을 곱할 때 연산하는 횟수 + 행렬k+1~j 연산 횟수
                int temp = AtoB[i][k] + matrix[i].r * matrix[k].c * matrix[i+len].c + AtoB[k+1][i+len];
                if (temp < AtoB[i][i+len]) AtoB[i][i+len] = temp;
            }
        }
    }

    printf("%d", AtoB[0][N-1]);
}