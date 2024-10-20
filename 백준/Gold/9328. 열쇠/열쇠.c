#include <stdio.h>
#include <memory.h>

struct rc {
    int r, c;
};

int h, w;
char map[100][100];

struct rc entrance[400];
int entranceCnt;

_Bool hasKey[26];

_Bool v[100][100];

_Bool dfs(int r, int c, int *const ans) {
    static int d[4] = {0, 0, -1, 1};
    _Bool flag = 0; // key found

    v[r][c] = 1;
    if (map[r][c] == '*') return 0;
    else if ('A' <= map[r][c] && map[r][c] <= 'Z' && !hasKey[map[r][c]-'A']) return 0;

    if ('a' <= map[r][c] && map[r][c] <= 'z' && !hasKey[map[r][c]-'a']) {
        hasKey[map[r][c]-'a'] = 1;
        flag = 1;
    } else if (map[r][c] == '$') {
        (*ans)++;
        map[r][c] = '.';
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + d[i], nc = c + d[3-i];
        if (0 <= nr && nr < h && 0 <= nc && nc < w && !v[nr][nc]) flag |= dfs(nr, nc, ans);
    }

    return flag;
}

_Bool find(int *ans) {
    _Bool flag = 0;

    for (int i = 0; i < h; i += h-1) {
        for (int j = 0; j < w; j++) {
            if (map[i][j] == '*' || ('A' <= map[i][j] && map[i][j] <= 'Z' && !hasKey[map[i][j]-'A'])) continue;
            memset(v, 0, 100*100);
            flag |= dfs(i, j, ans);
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j += w-1) {
            if (map[i][j] == '*' || ('A' <= map[i][j] && map[i][j] <= 'Z' && !hasKey[map[i][j]-'A'])) continue;
            memset(v, 0, 100*100);
            flag |= dfs(i, j, ans);
        }
    }

    return flag;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &h, &w);
        getchar();

        entranceCnt = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%c", map[i]+j);
            }
            getchar();
        }
       
        memset(hasKey, 0, 26);

        char temp[27];
        scanf("%s", temp);
        for (int i = 0; temp[i] != '\0'; i++) hasKey[temp[i]-'a'] = 1;

        int ans = 0;
        while (1) {
            if (!find(&ans)) break;
        }

        printf("%d\n", ans);
    }

    return 0;
}