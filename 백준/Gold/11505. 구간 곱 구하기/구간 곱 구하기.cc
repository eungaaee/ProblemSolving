#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int *seg, *init;

ll Init(int n, int l, int r) {
    if (l == r) return seg[n] = init[l];
    int m = l+r>>1;
    return seg[n] = Init(n<<1, l, m) * Init(n<<1|1, m+1, r) % MOD;
}
ll Update(int n, int l, int r, int idx, int val) {
    if (idx < l || idx > r) return seg[n];
    if (l == r) return seg[n] = val;
    int m = l+r>>1;
    return seg[n] = Update(n<<1, l, m, idx, val) * Update(n<<1|1, m+1, r, idx, val) % MOD;
}
ll Query(int n, int l, int r, int L, int R) {
    if (L > r || R < l) return 1;
    if (L <= l && R >= r) return seg[n];
    int m = l+r>>1;
    return Query(n<<1, l, m, L, R) * Query(n<<1|1, m+1, r, L, R) % MOD;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    init = new int[N];
    seg = new int[2<<(int)ceil(log2(N))];
    for (int i = 0; i < N; i++) {
        cin >> init[i];
    }
    Init(1, 0, N-1);
    for (int i = 0; i < M+K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a==1) Update(1, 0, N-1, b-1, c);
        else cout << Query(1, 0, N-1, b-1, c-1) << '\n';
    }
    return 0;
}