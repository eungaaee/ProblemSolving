#include <iostream>
#include <queue>
using namespace std;
vector<int> tree[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> q;
    int n, cur, t1, t2;
    cin >> n;
    int parents[n + 1]{};
    for (int i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        tree[t1].push_back(t2);
        tree[t2].push_back(t1);
    }
    q.push(1);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < tree[cur].size(); i++) {
            if (!parents[tree[cur][i]]) {
                parents[tree[cur][i]] = cur;
                q.push(tree[cur][i]);
            }
        }
    }
    for (int i = 2; i <= n; i++)
        cout << parents[i] << '\n';
    return 0;
}