#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, X, Y;
    vector<int> A, B;
    cin >> N;
    if (N == 2) {
        X = 1, Y = 1;
        A.push_back(1), B.push_back(2);
    } else if (N % 3 == 0) {
        for (int i = 1; 3 * i <= N; i++) {
            A.push_back(3 * i - 2);
            A.push_back(3 * i - 1);
            B.push_back(3 * i);
        }
    } else if (N % 3 == 1) {
        for (int i = 1; 3 * i + 1 <= N; i++) {
            A.push_back(3 * i - 1);
            A.push_back(3 * i);
            B.push_back(3 * i + 1);
        }
    } else {
        A.push_back(1);
        B.push_back(2);
        for (int i = 1; 3 * i + 2 <= N; i++) {
            A.push_back(3 * i);
            A.push_back(3 * i + 1);
            B.push_back(3 * i + 2);
        }
    }
    X = A.size(), Y = B.size();
    cout << X << '\n';
    for (int i = 0; i < X; i++)
        cout << A[i] << ' ';
    cout << '\n'
         << Y << '\n';
    for (int i = 0; i < Y; i++)
        cout << B[i] << ' ';
    return 0;
}