#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, d, minD;
    string *mbti;
    cin >> t;
    while (t--) {
        minD = 100000000;
        cin >> n;
        mbti = new string[n];
        for (int i = 0; i < n; i++) {
            cin >> mbti[i];
        }
        if (n > 32) {
            cout << "0\n";
            continue;
        }
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    d = 0;
                    for (int l = 0; l < 4; l++) {
                        if (mbti[i][l] != mbti[j][l]) d++;
                        if (mbti[j][l] != mbti[k][l]) d++;
                        if (mbti[k][l] != mbti[i][l]) d++;
                    }
                    if (d < minD) minD = d;
                }
            }
        }
        cout << minD << '\n';
    }
    delete[] mbti;
    return 0;
}