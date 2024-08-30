#include <algorithm>
#include <iostream>
using namespace std;
int n, m, nums[8];
void narr(int num, int c) {
    static int arr[8];
    arr[c - 1] = num;
    if (c == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] >= num)
            narr(nums[i], c + 1);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    for (int i = 0; i < n; i++) {
        narr(nums[i], 1);
    }
}