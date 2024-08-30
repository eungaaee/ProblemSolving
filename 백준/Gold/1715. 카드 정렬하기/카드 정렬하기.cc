#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, t, ans = 0, a, b;
    priority_queue<int> size;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> t, size.push(-t);
    
    for (int i = 1; i < N; i++) {
        a = -size.top(); size.pop();
        b = -size.top(); size.pop();
        size.push(-a-b);
        ans += a+b;
    }
    cout << ans;
    return 0;
}