#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, arr[100000], d;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    d = arr[1] - arr[0];
    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i - 1] != d) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] + 1 << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++)
        cout << -1 << ' ';
    return 0;
}