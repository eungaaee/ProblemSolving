#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    long long ans = 0;
    int t;
    for (int i = 0; i < N; i++) {
        cin >> t;
        ans += t;
    }
    for (int i = 0; i < M; i++) {
        cin >> t;
        if (t > 0) ans *= t;
    }
    cout << ans;
    return 0;
}