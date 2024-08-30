#include <algorithm>
#include <iostream>
using namespace std;
int n, m, nums[8];
void narr(int c) {
    static int ans[8];
    int recent{};
    if (c == m) {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] != recent) {
            if (c >= 1 && nums[i] < ans[c - 1])
                continue;
            recent = nums[i];
            ans[c] = nums[i];
            narr(c + 1);
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
    narr(0);
}