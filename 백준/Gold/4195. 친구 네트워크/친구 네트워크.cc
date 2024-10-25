#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> cardinalNum;

string find(string x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

string makeUnion(string x, string y) { // returns min(x, y);
    x = find(x);
    y = find(y);

    if (cardinalNum.find(x) == cardinalNum.end()) cardinalNum[x] = 1;
    if (cardinalNum.find(y) == cardinalNum.end()) cardinalNum[y] = 1;

    if (x == y) return x;
    else if (x < y) {
        parent[y] = x;

        cardinalNum[x] += cardinalNum[y];
        cardinalNum[y] = 1;

        return x;
    } else {
        parent[x] = y;

        cardinalNum[y] += cardinalNum[x];
        cardinalNum[x] = 1;

        return y;
    }
}

bool isUnion(string x, string y) {
    return find(x) == find(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        parent.clear();
        cardinalNum.clear();
        
        int F;
        cin >> F;

        string a, b;
        for (int i = 0; i < F; i++) {
            cin >> a >> b;
            if (parent.find(a) == parent.end()) parent[a] = a;
            if (parent.find(b) == parent.end()) parent[b] = b;
            cout << cardinalNum[makeUnion(a, b)] << '\n';
        }
    }

    return 0;
}