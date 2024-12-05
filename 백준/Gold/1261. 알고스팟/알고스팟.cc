#include <cstdio>
#include <queue>
#include <tuple>
#define INF 1e9

using namespace std;

int main() {
    int M, N;
    scanf("%d%d", &M, &N);

    int maze[N][M]; // bool
    int dist[N][M];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", maze[i] + j);
            dist[i][j] = INF;
        }
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    bool v[N][M] = {};
    int d[4] = {0, 0, -1, 1};

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        auto [cost, r, c] = pq.top();
        pq.pop();

        if (v[r][c]) continue;
        else v[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + d[i];
            int nc = c + d[3-i];

            if (0 <= nr && nr < N && 0 <= nc && nc < M) {
                if (cost + maze[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = cost + maze[nr][nc];
                    pq.push({dist[nr][nc], nr, nc});
                }
            }
        }
    }

    printf("%d", dist[N-1][M-1]);

    return 0;
}