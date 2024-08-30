#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, A, B, a, b, r;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> A >> B;
        if (A>B) a = A, b = B;
        else a = B, b = A;
        while (b) {
            r = a;
            a = b;
            b = r % b;
        }
        cout << A*B / a << '\n';
    }
    return 0;
}