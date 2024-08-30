#include <bits/stdc++.h>
using namespace std;

int main() {
    char s[101];
    int loc[26]{};
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++) {
        char cur = s[i]-97;
        if (loc[cur]) continue;
        else loc[cur] = i+1;
    }
    for (int i = 0; i < 26; i++)
        cout << loc[i]-1 << ' ';
    return 0;    
}