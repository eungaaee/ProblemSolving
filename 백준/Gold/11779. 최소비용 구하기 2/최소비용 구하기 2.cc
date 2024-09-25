#include <iostream>
#include <vector>
#include <queue>

#define INF 0x7fffffff

using namespace std;

void dijkstra(vector<pair<int, int>> bus[], int (&dist)[1001], int (&prev)[1001], const int &start, const int &end) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    dist[start] = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost > dist[cur]) continue; // 오래된 정보는 버린다.

        for (int i = 0; i < bus[cur].size(); i++) {
            int to = bus[cur][i].first;
            int viaCost = bus[cur][i].second;

            if (dist[to] > cost + viaCost) {
                dist[to] = cost + viaCost;
                pq.push({-dist[to], to});

                prev[to] = cur; // 경로 저장
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> bus[1001];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }

    int start, end;
    cin >> start >> end;

    int dist[1001], prev[1001];
    for (int i = 1; i <= 1000; i++) dist[i] = INF;
    prev[start] = -1;

    dijkstra(bus, dist, prev, start, end);

    // 경로 역추적
    int path[1001], pathIdx = 0;
    for (int i = end; i != -1; i = prev[i]) path[pathIdx++] = i;

    cout << dist[end] << '\n';
    cout << pathIdx << '\n';
    for (int i = pathIdx-1; i >= 0; i--) cout << path[i] << ' ';

    return 0;
}