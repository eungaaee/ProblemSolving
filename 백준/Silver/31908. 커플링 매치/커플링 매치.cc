#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string p, s;
    map<string, pair<string, string>> ring;
    vector<pair<string, string>> couples;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p >> s;
        if (s == "-") continue;
        
        if (ring.find(s) == ring.end()) ring[s] = {p, "notyet"};
        else if (ring[s].second == "notyet") ring[s].second = p;
        else ring[s].second = "nono";
    }

    for (auto i: ring) {
        if (i.second.second == "notyet" || i.second.second == "nono") continue;
        couples.push_back({i.second.first, i.second.second});
    }
    
    cout << couples.size();
    for (int i = 0; i < couples.size(); i++)
        cout << '\n' << couples[i].first << ' ' << couples[i].second;
    return 0;
}