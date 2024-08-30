#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, fix = 0;
    char A[2000], C, c1, c2, op;
    cin >> N;
    cin >> A[0];
    for (int i = 1; i < N; ++i) {
        cin >> A[i];
        if (i%2==0 && i <= N-3) {
            c1 = A[i-2], c2 = A[i], op = A[i-1];
            if (op == '&' && c1 == 'T' && c2 == 'T')
                A[i] = 'T';
            else if (op == '|' && (c1 == 'T' || c2 == 'T'))
                A[i] = 'T';
            else
                A[i] = 'F';
        }
    }
    cin >> C;
    if (N == 1) {
        fix = A[0] != C;
    } else {
        c1 = A[N-3], c2 = A[N-1], op = A[N-2];
        if (C == 'T') {
            if (op == '&') {
                if (c1 == 'T' && c2 == 'T') fix = 0;
                else if (c1 == 'T' && c2 == 'F') fix = 1;
                else if (c1 == 'F' && c2 == 'T') fix = 1;
                else if (c1 == 'F' && c2 == 'F') fix = 2;
            } else if (op == '|') {
                if (c1 == 'T' && c2 == 'T') fix = 0;
                else if (c1 == 'T' && c2 == 'F') fix = 0;
                else if (c1 == 'F' && c2 == 'T') fix = 0;
                else if (c1 == 'F' && c2 == 'F') fix = 1;
            }
        } else if (C == 'F') {
            if (op == '&') {
                if (c1 == 'T' && c2 == 'T') fix = 1;
                else if (c1 == 'T' && c2 == 'F') fix = 0;
                else if (c1 == 'F' && c2 == 'T') fix = 0;
                else if (c1 == 'F' && c2 == 'F') fix = 0;
            } else if (op == '|') {
                if (c1 == 'T' && c2 == 'T') fix = 2;
                else if (c1 == 'T' && c2 == 'F') fix = 1;
                else if (c1 == 'F' && c2 == 'T') fix = 1;
                else if (c1 == 'F' && c2 == 'F') fix = 0;
            }
        }
    }
    cout << fix;
    return 0;
}