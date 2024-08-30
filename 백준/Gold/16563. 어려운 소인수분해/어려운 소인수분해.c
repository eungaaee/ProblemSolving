#include <stdio.h>

int minFactor[5000001];

void findFactors() {
    for (int i = 2; i <= 5000000; i++) minFactor[i] = i;
    for (int i = 2; i*i <= 5000000; i++) {
        if (minFactor[i] != i) continue;
        for (int j = i*i; j <= 5000000; j += i) {
            if (minFactor[j] != j) continue;
            minFactor[j] = i;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    findFactors();

    while (N--) {
        int k;
        scanf("%d", &k);
        while (k > 1) {
            printf("%d ", minFactor[k]);
            k /= minFactor[k];
        }
        putchar('\n');
    }
    
    return 0;
}