#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, damage, time, maxDoT = 0, maxTime = 0x3f3f3f3f;
    vector<pair<int, int>> v;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> damage >> time;
        v.push_back({-damage, -time});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < M; i++) {
        maxDoT += -v[i].first;
        if (-v[i].second < maxTime) maxTime = -v[i].second;
    }
    cout << maxDoT << ' ' << maxTime;
    return 0;
}