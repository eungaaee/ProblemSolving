#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second) return a.second > b.second;
    else if (a.first.size() != b.first.size()) return a.first.size() > b.first.size();
    else return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    string word;
    unordered_map<string, int> freq;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> word;
        if (word.size() >= M) freq[word]++;
    }
    vector<pair<string, int>> words(freq.begin(), freq.end());
    sort(words.begin(), words.end(), compare);
    for (int i = 0; i < words.size(); i++)
        cout << words[i].first << '\n';
    return 0;
}