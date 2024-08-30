#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M, K;
ll *v, *seg;
ll Init(int node, int left, int right) {
    if (left == right) return seg[node] = v[left];
    int mid = left + right >> 1;
    return seg[node] = Init(node << 1, left, mid) + Init(node << 1 | 1, mid + 1, right);
}
void Update(int idx, ll val, int node, int left, int right) {
    if (idx < left || idx > right) return;
    if (left == right) {
        seg[node] = val;
        return;
    }
    int mid = left + right >> 1;
    Update(idx, val, node << 1, left, mid);
    Update(idx, val, node << 1 | 1, mid + 1, right);
    seg[node] = seg[node<<1] + seg[node<<1|1];
}
ll Query(int node, int L, int R, int left, int right) {
    if (L > right || R < left) return 0;
    if (L <= left && R >= right) return seg[node];
    int mid = left + right >> 1;
    return Query(node << 1, L, R, left, mid) + Query(node << 1 | 1, L, R, mid + 1, right);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    v = new ll[N];
    int h = (int)ceil(log2(N));
    seg = new ll[2 << h];
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    Init(1, 0, N - 1);
    for (int i = 0; i < M + K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            Update(b - 1, c, 1, 0, N - 1);
        } else {
            ll ans = Query(1, b - 1, c - 1, 0, N - 1);
            cout << ans << '\n';
        }
    }
    return 0;
}