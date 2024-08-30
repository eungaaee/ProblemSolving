#include <bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2) {
    if (n1 < n2) n1^=n2, n2^=n1, n1^=n2;
    int r;
    do {
        r = n1 % n2;
        n1 = n2;
        n2 = r;
    } while (r);
    return n1;
}

int main() {
    int u1, d1, u2, d2, divisor;
    cin >> u1 >> d1 >> u2 >> d2;

    divisor = gcd(d1, d2);
    int D = d1*d2 / divisor, U = u1 * d2/divisor + u2 * d1/divisor;
    divisor = gcd(D, U);
    cout << U/divisor << ' ' << D/divisor;
    return 0;
}