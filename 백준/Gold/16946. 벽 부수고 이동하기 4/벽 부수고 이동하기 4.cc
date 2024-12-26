#include <iostream>
#include <queue>

using namespace std;

int color_count[1000000];
int color_map[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int map[N][M];
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++) {
            map[i][j] = temp[j] - '0';
        }
    }

    // Flood Fill
    const int d[4] = {0, 0, -1, 1};
    int color = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1 || color_map[i][j] > 0) continue;

            color_map[i][j] = color;
            color_count[color] = 1;
            queue<pair<int, int>> q;
            q.push({i, j});

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + d[k];
                    int nc = c + d[3-k];

                    if (0 <= nr && nr < N && 0 <= nc && nc < M && map[nr][nc] == 0 && color_map[nr][nc] == 0) {
                        color_map[nr][nc] = color;
                        color_count[color]++;
                        q.push({nr, nc});
                    }
                }
            }

            color++;
        }
    }

    bool visited[color];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) continue;

            for (int k = 0; k < color; k++) visited[k] = false;
            for (int k = 0; k < 4; k++) {
                int nr = i + d[k];
                int nc = j + d[3-k];

                if (0 <= nr && nr < N && 0 <= nc && nc < M && color_map[nr][nc] > 0 && !visited[color_map[nr][nc]]) {
                    map[i][j] += color_count[color_map[nr][nc]];
                    visited[color_map[nr][nc]] = true;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] % 10;
        }
        cout << '\n';
    }

    return 0;
}