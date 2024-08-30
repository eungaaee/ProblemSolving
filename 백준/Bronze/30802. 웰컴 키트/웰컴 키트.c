#include <stdio.h>

int main() {
    int N, sizeAmount[6], T, P;
    scanf("%d", &N);
    for (int i = 0; i < 6; i++) scanf("%d", &sizeAmount[i]);
    scanf("%d%d", &T, &P);
    
    int tsum = 0;
    for (int i = 0; i < 6; i++) tsum += sizeAmount[i] / T + (sizeAmount[i] % T > 0);
    printf("%d\n%d %d", tsum, N/P, N%P);
    return 0;
}