#include <iostream>
#include <queue>
using namespace std;
int m, n, **box;
queue<pair<pair<int, int>, int>> q;
int bfs() {
    const int d[4] = {0, 0, -1, 1};
    int x, y, c, dx, dy, maxC{0};
    while (!q.empty()) {
        x = q.front().first.first;
        y = q.front().first.second;
        c = q.front().second;
        maxC = c > maxC ? c : maxC;
        for (int i = 0; i < 4; i++) {
            dx = x + d[i];
            dy = y + d[3 - i];
            if (dx >= 0 && dy >= 0 && dx < n && dy < m && box[dx][dy] == 0) {
                q.push(make_pair(make_pair(dx, dy), c + 1));
                box[dx][dy] = 2;
            }
        }
        q.pop();
    }
    return maxC;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    box = new int*[n];
    for (int i = 0; i < n; i++) {
        box[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push(make_pair(make_pair(i, j), 0));
            }
        }
    }
    int res = bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << res;
    for (int i = 0; i < n; i++) delete[] box[i];
    delete[] box;
    return 0;
}