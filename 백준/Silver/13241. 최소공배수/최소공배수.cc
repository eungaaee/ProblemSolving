#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, r=-1, ans;
    cin >> A >> B;
    ans = A*B;
    if (A<B) A^=B, B^=A, A^=B;
    while (r) {
        r = A % B;
        A = B;
        B = r;
    }
    cout << ans / A;
    return 0;
}