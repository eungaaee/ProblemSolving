#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    stack<int> s1, s2, s3, s4;
    bool possible = true;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (s1.empty() || num > s1.top()) s1.push(num);
        else if (s2.empty() || num > s2.top()) s2.push(num);
        else if (s3.empty() || num > s3.top()) s3.push(num);
        else if (s4.empty() || num > s4.top()) s4.push(num);
        else {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES" : "NO");

    return 0;
}