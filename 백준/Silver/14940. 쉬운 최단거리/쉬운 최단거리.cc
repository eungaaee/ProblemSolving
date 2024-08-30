#include <iostream>
#include <queue>
using namespace std;
int **map, n, m;
void bfs(int sx, int sy) {
    int x, y, d[4] = {0, 0, -1, 1}, dx, dy, c;
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(sx, sy), 0));
    map[sx][sy] = 0;
    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        c = q.front().second;
        for (int i = 0; i < 4; i++) {
            dx = x + d[i];
            dy = y + d[3 - i];
            if (dx >= 0 && dy >= 0 && dx < n && dy < m && map[dx][dy] == 1) {
                q.push(make_pair(make_pair(dx, dy), c + 1));
                map[dx][dy] = -(c + 1);
            }
        }
        q.pop();
    }
}
int main() {
    int t, sx, sy;
    cin >> n >> m;
    map = new int *[n];
    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> t;
            if (t == 2) {
                sx = i;
                sy = j;
                map[i][j] = 0;
            } else
                map[i][j] = t;
        }
    }
    bfs(sx, sy);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) cout << "-1 ";
            else cout << -map[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++) delete[] map[i];
    delete[] map;
    return 0;
}