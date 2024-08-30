#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, *h, left, right, mid, max{}, maxHeight;
    long long woods;
    cin >> n >> m;
    h = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        max = h[i] > max ? h[i] : max;
    }
    left = 0, right = max;
    while (left <= right) {
        mid = (left + right) / 2;
        woods = 0;
        for (int i = 0; i < n; i++) {
            woods += h[i] - mid > 0 ? h[i] - mid : 0;
        }
        if (woods < m) {
            right = mid - 1;
        } else if (woods >= m) {
            left = mid + 1;
            maxHeight = mid;
        }
    }
    cout << maxHeight;
    delete[] h;
    return 0;
}