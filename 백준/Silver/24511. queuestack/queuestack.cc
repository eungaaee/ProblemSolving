#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, B, M, C, Q[100000], tail = 0, p;
    bool A[100000];

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> B;
        if (!A[i]) Q[tail++] = B;
    }
    cin >> M;
    p = tail-1;
    if (p < 0) {
        for (int i = 0; i < M; i++) {
            cin >> C;
            cout << C << ' ';
        }
    } else {
        for (int i = 0; i < M; i++) {
            cin >> C;
            cout << Q[p] << ' ';
            Q[p] = C;
            if (p <= 0) p = tail-1;
            else p--;
        }
    }
    return 0;
}