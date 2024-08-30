#include <bits/stdc++.h>
using namespace std;

int n, m, s[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(s, s+n);
    int t, ans = n;
    for (int i = 0; i < m; i++) {
        cin >> t;
        int l = 0, r = n-1, mid;
        while (l <= r) {
            mid = l+r>>1;
            if (s[mid] == t) {
                ans--;
                break;
            }
            else if (s[mid] < t) l = mid+1;
            else r = mid-1;
        }
        if (l>r) ans++;
    }
    cout << ans;
    return 0;
}