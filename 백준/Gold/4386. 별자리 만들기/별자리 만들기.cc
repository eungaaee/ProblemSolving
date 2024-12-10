#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// cpp는 typedef 안 해도 한 것과 같음
struct xy {
    float x, y;
};

float distance(xy& a, xy& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout.precision(2); // 소수점 2자리
    cout << fixed; // 지수표기법 x

    int n;
    cin >> n;

    xy star[n];

    for (int i = 0; i < n; i++) {
        cin >> star[i].x >> star[i].y;
    }

    bool visited[n] = {};
    float ans = 0;

    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
    pq.push({0, 0});

    while(!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (visited[cur]) continue;
        else visited[cur] = true;

        ans += cost;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                pq.push({distance(star[cur], star[i]), i});
            }
        }
    }

    cout << ans;

    return 0;
}