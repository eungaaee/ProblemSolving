#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) break;

        int ans = 0;
        vector<pair<int, int>> road[m+1];
        for (int i = 0, x, y, z; i < n; i++) {
            cin >> x >> y >> z;
            road[x].push_back({z, y});
            road[y].push_back({z, x});
            ans += z;
        }

        bool visited[m+1] = {};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, 1});
        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();

            if (visited[cur]) continue;
            else visited[cur] = true;

            ans -= cost;
            for (auto& i: road[cur]) {
                if (!visited[i.second]) pq.push(i);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}