#include <iostream>
using namespace std;
int main() {
    int t, n, pattern[40]{1, 1};
    cin >> t;
    for (int i = 2; i <= 39; i++) {
        pattern[i] = pattern[i - 1] + pattern[i - 2];
    }
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 0) {
            cout << "1 0" << '\n';
        } else if (n == 1) {
            cout << "0 1" << '\n';
        } else {
            cout << pattern[n - 2] << ' ' << pattern[n - 1] << '\n';
        }
    }
    return 0;
}