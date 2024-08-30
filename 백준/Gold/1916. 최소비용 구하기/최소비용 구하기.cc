#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int st, dest;
vector<pair<int, int>> v[1001];
int dist[1001];

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    dist[st] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int nxt = v[cur][i].first, ncost = cost+v[cur][i].second;
            if (ncost < dist[nxt]) {
                dist[nxt] = ncost;
                pq.push({ncost, nxt});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    cin >> st >> dest;
    Dijkstra();
    cout << dist[dest];
    return 0;
}