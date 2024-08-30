#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, m, n, x, y, c;
    cin >> t;
    while (t--) {
        c = -1;
        cin >> m >> n >> x >> y;
        x -= 1;
        y -= 1;
        for (int i = x; i < m * n; i += m) {
            if (i % m == x && i % n == y) {
                c = i + 1;
                break;
            }
        }
        cout << c << '\n';
    }
    return 0;
}