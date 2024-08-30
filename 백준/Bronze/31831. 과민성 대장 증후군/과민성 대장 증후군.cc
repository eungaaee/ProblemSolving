#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, ds, sum = 0, c = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> ds;
        sum += ds;
        if (sum < 0) sum = 0;
        if (sum >= M) c++;
    }
    cout << c;
    return 0;
}