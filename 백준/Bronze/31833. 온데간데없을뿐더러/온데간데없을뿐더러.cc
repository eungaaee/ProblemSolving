#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string A, B, e;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> e;
        A += e;
    }
    for (int i = 0; i < N; i++) {
        cin >> e;
        B += e;
    }
    if (stoll(A) < stoll(B)) cout << A;
    else cout << B;
    return 0;
}