#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree[10000];
bool v[10000];
int maxNode, maxCost;

void dfs(int cur, int cost) {
    if (v[cur]) return;
    v[cur] = 1;
    if (cost > maxCost) maxCost = cost, maxNode = cur;
    for (int i = 0; i < tree[cur].size(); i++)
        dfs(tree[cur][i].first, cost+tree[cur][i].second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, e, c;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> s >> e >> c;
        tree[s-1].push_back({e-1, c});
        tree[e-1].push_back({s-1, c});
    }
    dfs(0, 0);
    for (int i = 0; i < 10000; i++)
        v[i] = 0;
    maxCost = 0;
    dfs(maxNode, maxCost);
    cout << maxCost;
    return 0;
}