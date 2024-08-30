#include <iostream>
#include <queue>
#include <set>
#include <memory.h>
using namespace std;

struct rc {
    int r;
    int c;
};

int N, map[100][100], dist, minDist = 0x3f3f3f3f;
bool v[100][100];
set<pair<int, int>> edge[10001];

void numberingDFS(int &r, int &c, int &island) {
    if (v[r][c]) return;
    v[r][c] = 1;
    map[r][c] = island;

    int nr, nc;
    const int d[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        nr = r+d[i];
        nc = c+d[3-i];
        if (0 <= nr && nr < N && 0 <= nc && nc < N) {
            if (!map[nr][nc]) edge[island].insert({r, c});
            else numberingDFS(nr, nc, island);
        }
    }
}

void BFS(int &island) {
    queue<rc> q;
    for (auto i: edge[island]) q.push({i.first, i.second});
    
    int r, c, nr, nc, depth = 0;
    const int d[4] = {0, 0, -1, 1};
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            r = q.front().r;
            c = q.front().c;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                nr = r+d[i];
                nc = c+d[3-i];
                if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                    if (map[nr][nc] > 0 && map[nr][nc] != island) {
                        dist = depth;
                        return;
                    } else if (!map[nr][nc] && !v[nr][nc]) {
                        v[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        depth++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    // 육지 번호 붙이기
    int islandNum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] && !v[i][j]) {
                islandNum++;
                numberingDFS(i, j, islandNum);
            }
        }
    }

    for (int i = 1; i <= islandNum; i++) {
        memset(v, 0, 10000);

        BFS(i);
        if (dist < minDist) minDist = dist;
    }
    cout << minDist;

    return 0;
}