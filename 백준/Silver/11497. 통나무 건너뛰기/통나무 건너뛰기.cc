#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, N, L[10000], max;
    cin >> T;
    while (T--) {
        max = 0;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> L[i];
        sort(L, L+N);
        for (int i = 2; i < N; i++)
            if (L[i] - L[i-2] > max) max = L[i] - L[i-2];
        if (L[1] - L[0] > max) max = L[1] - L[0];
        if (L[N-1] - L[N-2] > max) max = L[N-1] - L[N-2];
        cout << max << '\n';
    }
    return 0;
}