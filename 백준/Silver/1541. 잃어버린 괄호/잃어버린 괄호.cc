#include <iostream>
#include <string>
using namespace std;
int main() {
    string exprs;
    int memory{}, p{}, sum{}, i;
    bool isNeg = 0;
    cin >> exprs;
    for (i = 0; i < exprs.length(); i++) {
        if (exprs[i] == '+' || exprs[i] == '-') {
            if (isNeg)
                memory += stoi(exprs.substr(p, i));
            else
                sum += stoi(exprs.substr(p, i));
            p = i + 1;
        }
        isNeg = exprs[i] == '-' ? 1 : isNeg;
    }
    if (isNeg) {
        memory += stoi(exprs.substr(p, i));
        sum -= memory;
    } else
        sum += stoi(exprs.substr(p, i));
    cout << sum;
}