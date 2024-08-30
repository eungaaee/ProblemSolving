#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y, c{}, s, ms{}, d[4]{0, 0, -1, 1}, nx, ny;
    bool paper[500][500];
    queue<pair<int, int>> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> paper[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (paper[i][j]) {
                c++;
                s = 1;
                paper[i][j] = 0;
                q.push({i, j});
                while (!q.empty()) {
                    x = q.front().first;
                    y = q.front().second;
                    for (int i = 0; i < 4; i++) {
                        nx = x + d[i];
                        ny = y + d[3 - i];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                            if (paper[nx][ny]) {
                                s++;
                                paper[nx][ny] = 0;
                                q.push({nx, ny});
                            }
                        }
                    }
                    q.pop();
                }
                if (s > ms) ms = s;
            }
        }
    }
    cout << c << '\n'
         << ms;
}