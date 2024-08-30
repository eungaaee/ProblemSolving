#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    bool np[10001] = {};
    for (int i = 2; i*i <= 10000; i++) {
        if (np[i]) continue;
        for (int j = i*i; j <= 10000; j+=i) {
            np[j] = 1;
        }
    }
    
    int T;
    cin >> T;
    int n, x, y;
    while (T--) {
        cin >> n;
        x = y = n/2;
        for (int i = 0; i < n/2; i++) {
            if (np[x] || np[y]) {
                x--, y++;
                continue;
            }
            cout << x << ' ' << y << '\n';
            break;
        }
    }
    return 0;
}