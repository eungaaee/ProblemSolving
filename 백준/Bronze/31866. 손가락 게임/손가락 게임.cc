#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;
    
    char ans;
    if (a == 0 && b == 0) ans = '=';
    else if (a == 0 && b == 2) ans = '>';
    else if (a == 0 && b == 5) ans = '<';
    else if (a == 2 && b == 0) ans = '<';
    else if (a == 2 && b == 2) ans = '=';
    else if (a == 2 && b == 5) ans = '>';
    else if (a == 5 && b == 0) ans = '>';
    else if (a == 5 && b == 2) ans = '<';
    else if (a == 5 && b == 5) ans = '=';
    else if ((a == 1 || a == 3 || a == 4) && (b != 1 && b != 3 && b != 4)) ans = '<';
    else if ((a != 1 && a != 3 && a != 4) && (b == 1 || b == 3 || b == 4)) ans = '>';
    else if ((a == 1 || a == 3 || a == 4) && (b == 1 || b == 3 || b == 4)) ans = '=';
    cout << ans;
    return 0;
}