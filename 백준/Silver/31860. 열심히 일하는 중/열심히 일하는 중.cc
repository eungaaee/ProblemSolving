#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K, di, Y = 0, P, day = 0;
    priority_queue<int> D;
    queue<int> satis;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> di;
        D.push(di);
    }
    while (!D.empty()) {
        P = D.top();
        D.pop();
        Y = Y / 2 + P;
        satis.push(Y);
        P -= M;
        if (P > K) D.push(P);
        day++;
    }
    cout << day << '\n';
    for (int i = 0; i < day; i++) {
        cout << satis.front() << '\n';
        satis.pop();
    }
    return 0;
}