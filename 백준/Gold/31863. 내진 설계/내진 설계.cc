#include <bits/stdc++.h>
using namespace std;

struct p {
    int x, y, wave;
};

int m[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, b = 0;
    queue<p> q;
    cin >> N >> M;
    string l;
    for (int i = 0; i < N; i++) {
        cin >> l;
        for (int j = 0; j < l.size(); j++) {
            m[i][j] = l[j];
            if (l[j] == '@') q.push({i, j, 1}), m[i][j] = 0;
            else if (l[j] == '.') m[i][j] = 0;
            else if (l[j] == '*') m[i][j] = 1, b++;
            else if (l[j] == '#') m[i][j] = 2, b++;
            else m[i][j] = -1;
        }
    }

    int x, y, w, c = 0;
    int dx[] = {-1, -2, 1, 2, 0, 0, 0, 0},
        dy[] = {0, 0, 0, 0, -1, -2, 1, 2},
        d[] = {0, 0, -1, 1};
    while (!q.empty()) {
        w = q.front().wave;
        if (w == 1) { // 본진
            for (int i = 0; i < 8; i++) {
                x = q.front().x + dx[i];
                y = q.front().y + dy[i];
                if (m[x][y] == -1 || x < 0 || y < 0 || x >= N || y >= M) {
                    if (dx[i]==-1 || dx[i]==1 || dy[i]==-1 || dy[i]==1) i++;
                    continue;
                }
                else if (m[x][y] == 1) m[x][y] = 0, c++, q.push({x, y, 2});
                else if (m[x][y] == 2) m[x][y] = 1;
            }
        } else if (w == 2) { // 여진
            for (int i = 0; i < 4; i++) {
                x = q.front().x + d[i];
                y = q.front().y + d[3-i];
                if (x < 0 || y < 0 || x >= N || y >= M) continue;
                if (m[x][y] == -1) continue;
                else if (m[x][y] == 1) m[x][y] = 0, c++, q.push({x, y, 2});
                else if (m[x][y] == 2) m[x][y] = 1;
            }
        }
        q.pop();
    }

    cout << c << ' ' << b-c;
    return 0;
}