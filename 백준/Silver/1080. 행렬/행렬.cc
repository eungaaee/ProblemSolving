#include <cstdio>
using namespace std;

int main() {
    int N, M, A[50][50], B[50][50];
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            scanf("%1d", &A[i][j]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            scanf("%1d", &B[i][j]);
    }

    int minCal = 0;
    for (int i = 0; i < N-2; i++) {
        for (int j = 0; j < M-2; j++) {
            if (A[i][j] == B[i][j]) continue;
            for (int k = i; k <= i+2; k++) {
                for (int l = j; l <= j+2; l++) {
                    A[k][l] = 1 - A[k][l];
                }
            }
            minCal += 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", minCal);
    return 0;
}