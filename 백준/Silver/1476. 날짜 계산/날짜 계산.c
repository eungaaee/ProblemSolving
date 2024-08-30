#include <stdio.h>

int main() {
    int E, S, M;
    scanf("%d%d%d", &E, &S, &M);

    int y = 1;
    while ((y-E)%15 || (y-S)%28 || (y-M)%19) y++;
    printf("%d", y);
    
    return 0;
}