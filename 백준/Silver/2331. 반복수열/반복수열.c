#include <stdio.h>

int P, v[236197]; // 9^5 * 4

void dfs(int n) {
    if (v[n] == 2) return;
    v[n]++;

    int nxt = 0, pow;
    for (int t = n; t > 0; t /= 10) {
        pow = 1;
        for (int i = 0; i < P; i++) pow *= t%10;
        nxt += pow;
    }

    dfs(nxt);
}

int main() {
    int A;
    scanf("%d%d", &A, &P);
    
    dfs(A);

    int cnt = 0;
    for (int i = 1; i <= 236196; i++)
        if (v[i] == 1) cnt++;
    printf("%d", cnt);

    return 0;
}