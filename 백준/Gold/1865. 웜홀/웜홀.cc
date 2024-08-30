#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int dist[501];
vector<pair<int, int>> path[501];

void bellman_ford(int N) {
    int nxt, ncost;
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < path[i].size(); j++) {
                nxt = path[i][j].first, ncost = path[i][j].second;
                if (dist[nxt] > dist[i] + ncost) {
                    if (k == N) {
                        cout << "YES\n";
                        return;
                    }
                    dist[nxt] = dist[i] + ncost;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC, N, M, W;
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        for (int i = 1; i <= N; i++) {
            dist[i] = INF;
            path[i].clear();
        }
        int s, e, t;
        for (int i = 0; i < M; i++) {
            cin >> s >> e >> t;
            path[s].push_back({e, t});
            path[e].push_back({s, t});
        }
        for (int i = 0; i < W; i++) {
            cin >> s >> e >> t;
            path[s].push_back({e, -t});
        }
        bellman_ford(N);
    }
    return 0;
}