#include <stdio.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    _Bool pre_post[401][401] = {};

    for (int i = 0, a, b; i < k; i++) {
        scanf("%d%d", &a, &b);
        pre_post[a][b] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (pre_post[i][k] && pre_post[k][j])
                    pre_post[i][j] = 1;
            }
        }
    }

    int s;
    scanf("%d", &s);

    for (int i = 0, a, b; i < s; i++) {
        scanf("%d%d", &a, &b);

        if (pre_post[a][b]) printf("-1\n");
        else if (pre_post[b][a]) printf("1\n");
        else printf("0\n");
    }
    return 0;
}