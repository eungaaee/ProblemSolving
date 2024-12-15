#include <stdio.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);

    int A[N+1];
    A[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", A+i);
        A[i] += A[i-1];
    }

    int count = 0;
    int left = 0, right = 1;
    while (right <= N) {
        if (A[right] - A[left] < M) right++;
        else if (A[right] - A[left] > M) left++;
        else {
            count++;
            right++;
        }
    }

    printf("%d", count);

    return 0;
}