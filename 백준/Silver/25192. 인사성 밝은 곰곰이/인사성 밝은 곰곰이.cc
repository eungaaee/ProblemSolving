#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cnt = 0;
    string msg;
    set<string> user;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> msg;
        if (msg == "ENTER") user.clear();
        else if (!user.count(msg)) user.insert(msg), cnt++;
    }
    cout << cnt;
    return 0;
}