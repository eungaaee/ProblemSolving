#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int m, n, h, tomato[100][100][100], c;
queue<tuple<int, int, int>> q;
void bfs() {
    int x, y, z, qSize;
    const static int dx[6]{-1, 1, 0, 0, 0, 0}, dy[6]{0, 0, -1, 1, 0, 0}, dz[6]{0, 0, 0, 0, -1, 1};
    while (!q.empty()) {
        qSize = q.size();
        for (int cycle = 0; cycle < qSize; cycle++) {
            for (int i = 0; i < 6; i++) {
                x = get<0>(q.front()) + dx[i];
                y = get<1>(q.front()) + dy[i];
                z = get<2>(q.front()) + dz[i];
                if (x >= 0 && x < m && y >= 0 && y < n && z >= 0 && z < h && tomato[z][y][x] == 0) {
                    q.push({x, y, z});
                    tomato[z][y][x] = 1;
                }
            }
            q.pop();
        }
        c++;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (tomato[i][j][k] == 0) {
                    c = -1;
                    return;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1)
                    q.push({k, j, i});
                else if (tomato[i][j][k] == 0)
                    c = 1;
            }
        }
    }
    if (c) {
        c = -1;
        bfs();
        cout << c;
    } else
        cout << 0;
    return 0;
}