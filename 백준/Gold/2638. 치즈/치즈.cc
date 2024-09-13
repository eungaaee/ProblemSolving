#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, M;
int **monun;

struct xy {
    int x, y;
};

bool isRemain() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (monun[i][j] == 1) return true;
    return false;
}

bool isExposed(int r, int c) {
    int d[4] = {0, 0, -1, 1};

    int side = 0;
    for (int i = 0; i < 4; i++) {
        int rb = r + d[i], cb = c + d[3-i];
        if (monun[rb][cb] == -1) side++;
    }

    if (side >= 2) return true;
    else return false;
}

void markOutsideAir(int r = 0, int c = 0) {
    int d[4] = {0, 0, -1, 1};
    static bool v[100][100];

    if (!r & !c) memset(v, 0, 10000);

    v[r][c] = 1;
    monun[r][c] = -1;

    for (int i = 0; i < 4; i++) {
        int nr = r + d[i], nc = c + d[3-i];
        if (0 <= nr && nr < N && 0 <= nc && nc < M)
            if (!v[nr][nc] && monun[nr][nc] < 1)
                markOutsideAir(nr, nc);
    }
}

void melt(int *wave) {
    queue<xy> exposed;

    while (isRemain()) {
        markOutsideAir();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (monun[i][j] == 1 && isExposed(i, j)) exposed.push({i, j});
            }
        }

        while (!exposed.empty()) {
            xy cur = exposed.front();
            exposed.pop();

            monun[cur.x][cur.y] = -1;
        }

        (*wave)++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    monun = (int **)malloc(8 * N);
    for (int i = 0; i < N; i++) {
        monun[i] = (int *)malloc(4 * M);
        for (int j = 0; j < M; j++) cin >> monun[i][j];
    }

    int wave = 0;
    melt(&wave);
    cout << wave;

    for (int i = 0; i < N; i++) free(monun[i]);
    free(monun);

    return 0;
}