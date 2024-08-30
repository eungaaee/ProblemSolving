#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E, K;
    cin >> V >> E >> K;

    int u, v, w, dist[20001];
    vector<pair<int, int>> m[20001];
    for (int i = 1; i <= V; ++i) dist[i] = INF;
    for (int i = 0; i < E; ++i) {
        cin >> u >> v >> w;
        m[u].push_back({v, w});
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, K});
    dist[K] = 0;
    int cur, cost, nxt, ncost;
    while (!pq.empty()) {
        cur = pq.top().second;
        cost = -pq.top().first;
        pq.pop();
        for (int i = 0; i < m[cur].size(); ++i) {
            nxt = m[cur][i].first;
            ncost = m[cur][i].second;
            if (dist[nxt] > cost + ncost) {
                dist[nxt] = cost + ncost;
                pq.push({-dist[nxt], nxt});
            }
        }
    }
    for (int i = 1; i <= V; ++i) {
        if (dist[i] < INF) cout << dist[i];
        else cout << "INF";
        cout << '\n';
    }
    return 0;
}