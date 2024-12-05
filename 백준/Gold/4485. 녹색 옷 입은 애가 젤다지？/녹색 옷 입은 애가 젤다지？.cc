#include <iostream>
#include <queue>
#include <tuple>
#define INF 1e9

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, problem_i = 1;
    while (true) {
        cin >> N;
        if (N == 0) break;

        int cave[N][N];
        int dist[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cave[i][j];
                dist[i][j] = INF;
            }
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        bool visited[N][N] = {};
        int d[4] = {0, 0, -1, 1};

        dist[0][0] = cave[0][0];
        pq.push({dist[0][0], 0, 0});

        while (!pq.empty()) {
            auto [cost, r, c] = pq.top();
            pq.pop();

            if (visited[r][c]) continue;
            else visited[r][c] = true;

            for (int i = 0; i < 4; i++) {
                int nr = r + d[i];
                int nc = c + d[3-i];
                
                if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                    if (cost + cave[nr][nc] < dist[nr][nc]) {
                        dist[nr][nc] = cost + cave[nr][nc];
                        pq.push({dist[nr][nc], nr, nc});
                    }
                }
            }
        }

        cout << "Problem " << problem_i << ": " << dist[N-1][N-1] << '\n';
        problem_i++;
    }

    return 0;
}