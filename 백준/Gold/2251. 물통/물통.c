#include <stdio.h>

int A, B, C;
_Bool v[201][201][201];
int ans[200], p;

void dfs(int a, int b, int c) {
    if (v[a][b][c]) return;
    v[a][b][c] = 1;

    if (!a) ans[p++] = c;

    // A to B
    if (a+b > B) dfs(a+b-B, B, c);
    else dfs(0, a+b, c);
    // A to C
    if (a+c > C) dfs(a+c-C, b, C);
    else dfs(0, b, a+c);
    // B to A
    if (b+a > A) dfs(A, b+a-A, c);
    else dfs(b+a, 0, c);
    // B to C
    if (b+c > C) dfs(a, b+c-C, C);
    else dfs(a, 0, b+c);
    // C to A
    if (c+a > A) dfs(A, b, c+a-A);
    else dfs(c+a, b, 0);
    // C to B
    if (c+b > B) dfs(a, B, c+b-B);
    else dfs(a, c+b, 0);
}

int main() {
    scanf("%d%d%d", &A, &B, &C);

    dfs(0, 0, C);
    for (int i = 0; i < p-1; i++) {
        for (int j = p-1; j > i; j--) {
            if (ans[j-1] > ans[j])
                ans[j-1] ^= ans[j], ans[j] ^= ans[j-1], ans[j-1] ^= ans[j];
        }
    }
    for (int i = 0; i < p; i++) printf("%d ", ans[i]);

    return 0;
}