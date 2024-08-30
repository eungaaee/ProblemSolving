#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n, m;
    map<string, int> names;
    string t;
    vector<string> dutbojob;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
        names.insert(make_pair(t, i));
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        if (names.find(t) != names.end()) {
            dutbojob.push_back(t);
        }
    }
    sort(dutbojob.begin(), dutbojob.end());
    cout << dutbojob.end() - dutbojob.begin();
    for (string i : dutbojob) {
        cout << '\n' << i;
    }
    return 0;
}