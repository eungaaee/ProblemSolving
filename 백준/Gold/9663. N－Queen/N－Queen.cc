#include <bits/stdc++.h>
using namespace std;

int N, board[15], c;

inline int absolute(int n) {
    if (n < 0) return -n;
    else return n;
}

inline bool isAttackable(int row) {
    for (int i = 0; i < row; i++) {
        if (board[i] == board[row] || row-i == absolute(board[row]-board[i])) return 1;
    }
    return 0;
}

void rowCheck(int row) {
    if (row == N) {
        c++;
        return;
    }

    for (int i = 0; i < N; i++) {
        board[row] = i;
        if (isAttackable(row)) continue;
        rowCheck(row+1);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    rowCheck(0);
    cout << c;
    return 0;    
}