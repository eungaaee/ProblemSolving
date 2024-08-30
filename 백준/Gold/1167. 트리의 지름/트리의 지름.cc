#include <bits/stdc++.h>
using namespace std;

int v, maxCost, maxNode;
vector<pair<int, int>> tree[100001];
bool vis[100001];

void dfs(int cur, int cost) {
    if (vis[cur]) return;
    vis[cur] = 1;
    if (cost > maxCost) maxCost = cost, maxNode = cur;
    for (int i = 0; i < tree[cur].size(); i++) {
        int nxt = tree[cur][i].first, ncost = tree[cur][i].second;
        dfs(nxt, cost + ncost);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v;
    int from, to, dist;
    for (int i = 0; i < v; i++) {
        cin >> from;
        while (1) {
            cin >> to;
            if (to == -1) break;
            cin >> dist;
            tree[from].push_back({to, dist});
            tree[to].push_back({from, dist});
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= 100000; i++)
        vis[i] = 0;
    maxCost = 0;
    dfs(maxNode, 0);
    cout << maxCost;
    return 0;
}