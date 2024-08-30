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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, arr[100000];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    int divisor = arr[1]-arr[0];
    for (int i = 2; i < N; ++i) divisor = gcd(divisor, arr[i]-arr[i-1]);

    int c = 0;
    for (int i = 1; i < N; ++i)
        c += (arr[i] - arr[i-1]) / divisor - 1;
    cout << c;
    return 0;
}