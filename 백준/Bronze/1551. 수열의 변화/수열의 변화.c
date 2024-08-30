#include <stdio.h>

int main() {
    int N, K, arr[20];
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", arr+i);
        getchar();
    }

    for (int i = 0; i < K; i++) {
        for (int j = 1; j < N-i; j++)
            arr[j-1] = arr[j]-arr[j-1];
    }
    
    for (int i = 0; i < N-K-1; i++) printf("%d,", arr[i]);
    printf("%d", arr[N-K-1]);
    return 0;
}