#include <algorithm>
#include <iostream>
using namespace std;
int n, m, nums[8];
void narr(int c) {
    static bool visit[8];
    int t{};
    static int ans[8];
    if (c == m) {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visit[i] && nums[i] != t) {
            ans[c] = nums[i];
            t = nums[i];
            visit[i] = 1;
            narr(c + 1);
            visit[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    narr(0);
}