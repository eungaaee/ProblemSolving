#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, d, c;
        cin >> n >> d >> c;

        vector<pair<int, int>> dependency[n+1];

        for (int i = 0, a, b, s; i < d; i++) {
            cin >> a >> b >> s;
            dependency[b].push_back({s, a});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int dist[n+1];
        bool visited[n+1];
        for (int i = 0; i <= n; i++) {
            dist[i] = INF;
            visited[i] = false;
        }

        pq.push({0, c});
        dist[c] = 0;

        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();

            if (visited[cur]) continue;
            else visited[cur] = true;

            for (auto &i: dependency[cur]) {
                if (i.first + cost < dist[i.second]) {
                    dist[i.second] = i.first + cost;
                    pq.push({dist[i.second], i.second});
                }
            }
        }

        int count = 0;
        int time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] < INF) {
                count++;
                if (dist[i] > time) time = dist[i];
            }
        }
        cout << count << ' ' << time << '\n';
    }

    return 0;
}