#include <iostream>
using namespace std;
void dp(int n, int *c) {
    if (n == 0) {
        *c += 1;
    }
    if (n >= 3) {
        dp(n - 3, c);
    }
    if (n >= 2) {
        dp(n - 2, c);
    }
    if (n >= 1) {
        dp(n - 1, c);
    }
}
int main() {
    int t, n, c;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        c = 0;
        dp(n, &c);
        cout << c << '\n';
    }
    return 0;
}