#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, shake, apc;
    string name, hak, icpc;
    vector<pair<int, string>> participants;
    vector<string> qualifiers;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> name >> hak >> icpc >> shake >> apc;
        if (hak == "jaehak" && icpc == "notyet" && (shake > 3 || shake == -1)) participants.push_back({apc, name});
    }
    sort(participants.begin(), participants.end());

    int qs = participants.size();
    if (qs > 10) qs = 10;
    for (int i = 0; i < qs; i++) qualifiers.push_back(participants[i].second); 
    sort(qualifiers.begin(), qualifiers.end());

    cout << qs;
    for (int i = 0; i < qs; i++) cout << '\n' << qualifiers[i];
    return 0;
}