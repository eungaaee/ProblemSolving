#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    int N;
    scanf("%d", &N);

    // 에라토스테네스의 체
    _Bool *isPrime = (_Bool *)malloc(N+1);
    memset(isPrime, 1, N+1);
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i*i <= N; i++) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j <= N; j += i) {
            isPrime[j] = 0;
        }
    }

    // 소수 배열 민들기
    int *primeNums = (int *)malloc(N*4);
    int primeCnt = 0;

    for (int i = 0; i <= N; i++) {
        if (isPrime[i]) primeNums[primeCnt++] = i;
    }

    // 투 포인터
    int l = 0, r = 0, sum = 0, numofcases = 0;

    while (r <= primeCnt) {
        if (sum < N) sum += primeNums[r++];
        else sum -= primeNums[l++];
        
        if (sum == N) numofcases++;
    }

    printf("%d", numofcases);

    free(isPrime);
    free(primeNums);

    return 0;
}