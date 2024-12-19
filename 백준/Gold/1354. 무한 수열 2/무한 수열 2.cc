#include <iostream>
#include <unordered_map>

using namespace std;

long long N;
int P, Q, X, Y;
unordered_map<long long, long long> A;

long long seq(long long i) {
    if (i <= 0) return 1;
    else if (A.find(i) == A.end()) return A[i] = seq(i/P - X) + seq(i/Q - Y);
    else return A[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P >> Q >> X >> Y;
    cout << seq(N);

    return 0;
}