#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, k, x[10000];
    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    sort(x, x+N);
    cout << x[N-k];
    return 0;
}