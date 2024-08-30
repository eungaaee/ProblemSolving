#include <iostream>
using namespace std;

inline int toInteger(string n) {
    int ret = 0;
    for (register int i = 0; i < n.size(); i++) ret = ret * 10 + n[i]-'0';
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    int intA, intB, intC;
    cin >> A >> B >> intC;
    intA = toInteger(A), intB = toInteger(B);
    
    cout << intA + intB - intC << '\n';
    cout << toInteger(A + B) - intC;
    return 0;
}