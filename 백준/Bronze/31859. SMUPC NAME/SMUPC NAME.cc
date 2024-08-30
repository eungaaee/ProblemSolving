#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, narr[26] = {}, dup = 0, num;
    string S, ans;
    cin >> N >> S;
    for (int i = 0; i < S.size(); ++i) {
        if (narr[S[i]-'a'] > 0) {
            dup++;
        } else {
            narr[S[i]-'a'] = 1;
            ans += S[i];
        }
    }
    cout << "smupc_";
    num = dup+4;
    for (int i = 10; num > 0;) {
        cout << num%i;
        num /= i;
    }
    for (int i = ans.size()-1; i >= 0; --i)
        cout << ans[i];
    num = N + 1906;
    for (int i = 10; num > 0;) {
        cout << num%i;
        num /= i;
    }
    return 0;
}