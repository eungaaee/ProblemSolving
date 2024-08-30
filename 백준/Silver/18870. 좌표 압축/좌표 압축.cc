#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, left, right, mid, dupN;
    cin >> n;
    vector<int> x(n), sortedX;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sortedX = x;
    sort(sortedX.begin(), sortedX.end());
    sortedX.erase(unique(sortedX.begin(), sortedX.end()), sortedX.end());
    for (int i = 0; i < n; i++) {
        left = 0, right = sortedX.size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (sortedX[mid] < x[i])
                left = mid + 1;
            else if (sortedX[mid] > x[i])
                right = mid - 1;
            else
                break;
        }
        cout << mid << ' ';
    }
    return 0;
}