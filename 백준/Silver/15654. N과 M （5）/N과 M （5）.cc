#include <algorithm>
#include <iostream>
using namespace std;
int n, m, nums[8];
void narr(int &num, int c) {
    static int arr[8];
    bool isDup;
    arr[c - 1] = num;
    if (c == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        isDup = 0;
        for (int j = 0; j < n; j++) {
            if (nums[i] == arr[j]) {
                isDup = 1;
                break;
            }
        }
        if (!isDup) {
            narr(nums[i], c + 1);
            for (int i = c; i < n; i++)
                arr[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums, nums + n);
    for (int i = 0; i < n; i++)
        narr(nums[i], 1);
    return 0;
}