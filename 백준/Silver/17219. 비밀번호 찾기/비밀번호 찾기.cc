#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    map<string, string> urlpw;
    string url, pw;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> url >> pw;
        urlpw.insert(make_pair(url, pw));
    }
    for (int i = 0; i < m; i++) {
        cin >> url;
        cout << urlpw[url] << '\n';
    }
    return 0;
}