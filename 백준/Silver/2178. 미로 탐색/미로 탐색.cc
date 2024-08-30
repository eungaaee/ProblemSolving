#include <iostream>
#include <queue>
using namespace std;
queue<pair<pair<int, int>, int>> q;
int n, m, **maze, dx, dy, c;
int bfs() {
    const int d[4] = {0, 0, -1, 1};
    while (!q.empty()) {
        c = q.front().second;
        for (int i = 0; i < 4; i++) {
            dx = q.front().first.first + d[i];
            dy = q.front().first.second + d[3 - i];
            if (dx >= 0 && dy >= 0 && dx < n && dy < m && maze[dx][dy] == 1) {
                if (dx == n - 1 && dy == m - 1) return c + 1;
                maze[dx][dy] = 0;
                q.push(make_pair(make_pair(dx, dy), c + 1));
            }
        }
        q.pop();
    }
}
int main() {
    string line;
    cin >> n >> m;
    maze = new int*[n];
    for (int i = 0; i < n; i++) {
        maze[i] = new int[m];
        cin >> line;
        for (int j = 0; j < m; j++) {
            maze[i][j] = line[j] - 48;
        }
    }
    q.push(make_pair(make_pair(0, 0), 1));
    cout << bfs();
    for (int i = 0; i < n; i++)
        delete[] maze[i];
    delete[] maze;
    return 0;
}