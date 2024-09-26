#include <iostream>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

void dijkstra(int &start, int *(&dist), vector<pair<int, int>> (&way)[101]) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto &w : way[cur]) {
            int viaCost = w.second;
            int to = w.first;

            if (dist[to] > cost + viaCost) {
                dist[to] = cost + viaCost;
                pq.push({-dist[to], to});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    int *t = new int[n+1];
    for (int i = 1; i <= n; i++) cin >> t[i];

    vector<pair<int, int>> way[101];
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        
        way[a].push_back({b, l});
        way[b].push_back({a, l});
    }

    int *dist = new int[n+1];
    int maxSum = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dist[j] = INF;
        dijkstra(i, dist, way);

        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[j] <= m) sum += t[j];
        }
        if (maxSum < sum) maxSum = sum;
    }

    printf("%d", maxSum);

    delete[] t;
    delete[] dist;
    return 0;
}