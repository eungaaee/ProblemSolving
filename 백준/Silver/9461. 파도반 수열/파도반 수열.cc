#include <iostream>
using namespace std;
int main() {
    int t, n;
    long long p[100]{1, 1, 1, 2, 2};
    cin >> t;
    for (int i = 5; i < 100; i++) {
        p[i] = p[i - 1] + p[i - 5];
    }
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << p[n - 1] << '\n';
    }
    return 0;
}