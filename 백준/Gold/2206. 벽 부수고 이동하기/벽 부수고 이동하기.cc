#include <bits/stdc++.h>
using namespace std;

struct p {
    int x;
    int y;
    bool dashed;
};

bool m[1000][1000], v[1000][1000], vdash[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    queue<p> q;
    cin >> N >> M;
    string line;
    for (int i = 0; i < N; ++i) {
        cin >> line;
        for (int j = 0; j < M; j++) {
            m[i][j] = line[j] - '0';
        }
    }
    if (N == 1 && M == 1) {
        cout << 1;
        return 0;
    }
    q.push({0, 0, 0});
    int nx, ny, qs, depth = 0, d[4] = {0, 0, -1, 1};
    bool dashed;
    while (!q.empty()) {
        depth++;
        qs = q.size();
        for (int k = 0; k < qs; k++) {
            dashed = q.front().dashed;
            for (int i = 0; i < 4; i++) {
                nx = q.front().x + d[i];
                ny = q.front().y + d[3 - i];
                if (nx == N - 1 && ny == M - 1) {
                    cout << depth + 1;
                    return 0;
                }
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && !v[nx][ny]) {
                    if (dashed) {
                        if (!vdash[nx][ny] && !m[nx][ny]) {
                            vdash[nx][ny] = 1;
                            q.push({nx, ny, 1});
                        }
                    } else {
                        if (!dashed && !m[nx][ny]) {
                            v[nx][ny] = 1;
                            q.push({nx, ny, 0});
                        } else if (!vdash[nx][ny] && m[nx][ny]) {
                            vdash[nx][ny] = 1;
                            q.push({nx, ny, 1});
                        }
                    }
                }
            }
            q.pop();
        }
    }
    cout << -1;
    return 0;
}