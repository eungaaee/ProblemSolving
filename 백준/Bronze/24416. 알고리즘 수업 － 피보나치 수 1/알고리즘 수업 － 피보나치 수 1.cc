#include <bits/stdc++.h>
using namespace std;

int c1, c2, f[41];

int f1(int n) {
    if (n==1 || n==2) {
        c1++;
        return 1;
    } else return f1(n-1) + f1(n-2);
}

int f2(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
        c2++;
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;
    f1(n);
    f2(n);
    cout << c1 << ' ' << c2;
    return 0;
}