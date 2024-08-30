#include <stdio.h>
#include <memory.h>

int w, h;
_Bool map[51][51], v[51][51];

void dfs(int r, int c) {
    const int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1},
        dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    
    v[r][c] = 1;

    int nr, nc;
    for (int i = 0; i < 8; i++) {
        nr = r+dr[i], nc = c+dc[i];
        if (0 <= nr&&nr < h && 0 <= nc&&nc < w) {
            if (map[nr][nc] && !v[nr][nc]) {
                dfs(nr, nc);
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d%d", &w, &h);
        if (w+h == 0) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] && !v[i][j]) cnt++, dfs(i, j);
            }
        }
        printf("%d\n", cnt);

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                map[i][j] = v[i][j] = 0;
    }
    return 0;
}