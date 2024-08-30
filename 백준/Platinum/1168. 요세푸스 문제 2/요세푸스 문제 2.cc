#include <iostream>
using namespace std;

int seg[1<<18]; // h = log2(N) = 17.xx, 2^(h+1).

int init(int node, int l, int r) {
    if (l == r) return seg[node] = 1;
    int m = l+r >> 1;
    return seg[node] = init(node*2, l, m) + init(node*2+1, m+1, r);
}

int query(int node, int l, int r, int k) {
    if (l == r) return l;
    int m = l+r>>1;
    // 왼쪽 리프노드에 순서개(k) 이상의 원소가 남아있을 때 (들어갈 필요 있을 때)
    if (k <= seg[node*2]) return query(node*2, l, m, k);
    else return query(node*2+1, m+1, r, k-seg[node*2]); // k -> k-seg[node*2] 오른쪽 트리에서의 순서로 바꿔주기
}

int remove(int node, int l, int r, int k) {
    seg[node]--;
    if (l == r) return 0;
    int m = l+r>>1;
    if (k <= m) return remove(node*2, l, m, k);
    else return remove(node*2+1, m+1, r, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    init(1, 1, N);

    int cur = 1;
    cout << '<';
    for (int size = N; size > 1; size--) {
        cur += K-1, cur %= size;
        if (!cur) cur = size;

        int num = query(1, 1, N, cur);
        cout << num << ", ";
        remove(1, 1, N, num);
    }
    cout << query(1, 1, N, 1) << '>';

    return 0;
}