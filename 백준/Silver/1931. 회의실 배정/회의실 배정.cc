#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, a, b, start, end, c{};
    vector<pair<int, int>> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back(make_pair(b, a));
    }
    sort(v.begin(), v.end());
    start = v[0].second;
    end = v[0].first;
    c = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].second >= end) {
            start = v[i].second;
            end = v[i].first;
            c++;
        }
    }
    cout << c;
    return 0;
}