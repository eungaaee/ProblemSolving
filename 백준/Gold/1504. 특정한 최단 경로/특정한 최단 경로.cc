#include <iostream>
#include <vector>
#include <queue>

#define INF 0x7fffffff/3

using namespace std;

int N, E;
vector<pair<int, int>> graph[801];
int dist[801];

int dijkstra(int from, int to) {
    priority_queue<pair<int, int>> pq;

    pq.push({0, from});
    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[from] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int viaCost = cost + graph[cur][i].first;

            if (viaCost < dist[graph[cur][i].second]) {
                dist[graph[cur][i].second] = viaCost;
                pq.push({-viaCost, graph[cur][i].second});
            }
        }
    }

    return dist[to];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v1, v2;

    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    cin >> v1 >> v2;

    int ans1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    int ans2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);

    if (ans1 >= INF && ans2 >= INF) cout << -1;
    else cout << (ans1 < ans2 ? ans1 : ans2);

    return 0;
}