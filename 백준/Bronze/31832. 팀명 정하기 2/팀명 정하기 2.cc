#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, lower, upper, namesize;
    bool charcheck = 0;
    string name;
    cin >> N;
    for (int i = 0; i < N; i++) {
        lower = 0, upper = 0, charcheck = 0;
        cin >> name;
        namesize = name.size();
        if (namesize > 10) continue;
        for (int i = 0; i < name.size(); i++) {
            if (name[i] >= 'a' && name[i] <= 'z')
                lower++, charcheck = 1;
            else if (name[i] >= 'A' && name[i] <= 'Z')
                upper++, charcheck = 1;
            else if (name[i] == '-')
                charcheck = 1;
        }
        if (upper > lower) continue;
        if (!charcheck) continue;
        cout << name << '\n';
    }
    return 0;
}