#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int main() {
    int t, n, c;
    string name, type;
    map<string, int> types;
    cin >> t;
    for (int i = 0; i < t; i++) {
        c = 1;
        types.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> name >> type;
            if (types.find(type) == types.end()) {
                types.insert(make_pair(type, 1));
            } else {
                types[type] += 1;
            }
        }
        for (pair<string, int> i : types) {
            c *= (i.second + 1);
        }
        cout << c - 1 << '\n';
    }
}