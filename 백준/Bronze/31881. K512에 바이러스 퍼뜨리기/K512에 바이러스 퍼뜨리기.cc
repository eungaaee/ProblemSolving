#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    bool v[200001] = {};

    int q1, q2;
    for (int i = 0; i < Q; i++) {
        cin >> q1;
        if (q1 == 1) {
            cin >> q2;
            if (v[q2]) continue;
            v[q2] = 1, N--;
        } else if (q1 == 2) {
            cin >> q2;
            if (v[q2]) v[q2] = 0, N++;
        } else if (q1 == 3) cout << N << '\n';
    }
    return 0;
}