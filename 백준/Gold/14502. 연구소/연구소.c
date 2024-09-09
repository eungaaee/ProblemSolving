#include <stdio.h>

int N, M, map[8][8], virtualMap[8][8], virus[64][2], virusCnt, max;

// DFS
void epidemic(int r, int c, _Bool isInit) {
    static int d[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = r + d[i], nc = c + d[3-i];
        if (0 <= nr && nr < N && 0 <= nc && nc < M && !virtualMap[nr][nc]) {
            virtualMap[nr][nc] = 2;
            epidemic(nr, nc, 0);
        }
    }
}

void wallBacktrack(int wall) {
    if (wall == 3) {
        for (int tr = 0; tr < N; tr++)
            for (int tc = 0; tc < M; tc++)
                virtualMap[tr][tc] = map[tr][tc];

        for (int i = 0; i < virusCnt; i++) epidemic(virus[i][0], virus[i][1], 1);

        int safeArea = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (!virtualMap[i][j]) safeArea++;

        if (safeArea > max) max = safeArea;

        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!map[i][j]) {
                map[i][j] = 1;
                wallBacktrack(wall+1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                virus[virusCnt][0] = i;
                virus[virusCnt][1] = j;
                virusCnt++;
            }
        }
    }

    wallBacktrack(0);

    printf("%d", max);

    return 0;
}