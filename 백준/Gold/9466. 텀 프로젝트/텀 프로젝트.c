#include <stdio.h>

int n, s[100001], cnt;
_Bool v[100001], done[100001];

void dfs(int cur) {
    if (!v[cur]) {
        v[cur] = 1;
        dfs(s[cur]);
    } else if (v[cur] & !done[cur]) {
        for (int i = s[cur]; i != cur; i = s[i]) cnt--;
        cnt--;
        return;
    }
    done[cur] = 1;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", s+i);

        cnt = n;
        for (int i = 1; i <= n; i++) {
            if (!v[i]) dfs(i);
        }

        printf("%d\n", cnt);

        for (int i = 1; i <= n; i++) v[i] = done[i] = 0;
    }

    return 0;
}