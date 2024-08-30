#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int S, N=0;
    cin >> S;
    for (unsigned int i=1, sum=0; i < S; ++i) {
        if (static_cast<long long>(sum) + i <= S) sum += i, N++;
        else break;
    }
    cout << (S==1?1:N);
    return 0;
}