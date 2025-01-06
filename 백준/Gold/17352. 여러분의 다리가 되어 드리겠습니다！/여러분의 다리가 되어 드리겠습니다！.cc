#include <iostream>

using namespace std;

int parent[300001];

int Find(int x) {
    if (parent[x] == x) return x;
    else return parent[x] = Find(parent[x]);
}

void Unify(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x < y) parent[y] = x;
    else if (x > y) parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < N-2; i++) {
        int a, b;
        cin >> a >> b;
        Unify(a, b);
    }

    int prev = Find(1), cur;
    for (int i = 2; i <= N; i++) {
        cur = Find(i);

        if (cur != prev) break;
        else prev = Find(i);
    }

    cout << prev << ' ' << cur;

    return 0;
}