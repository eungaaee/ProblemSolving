#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, A[50], B[50], S=0;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    sort(A, A+N);
    sort(B, B+N);
    for (int i = 0; i < N; ++i)
        S += A[N-1-i]*B[i];
    cout << S;
    return 0;
}