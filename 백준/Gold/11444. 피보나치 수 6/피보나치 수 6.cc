#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

map<long long, int> memo;

long long fib(long long n) {
    if (memo.count(n) > 0) return memo[n];
    if (n & 1)
        return memo[n] = (fib(n / 2) * fib(n / 2) + fib(n / 2 + 1) * fib(n / 2 + 1)) % MOD;
    else
        return memo[n] = fib(n / 2) * (fib(n / 2 - 1) + fib(n / 2 + 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    memo[0] = 0, memo[1] = 1, memo[2] = 1;
    cout << fib(n);
    return 0;
}