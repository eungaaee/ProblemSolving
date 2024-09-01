#include <iostream>
#include <unordered_map>
using namespace std;

long long N;
int P, Q;
unordered_map<long long, long long> A;

long long getA(long long i) {
    if (A.find(i) != A.end()) return A[i];
    else return A[i] = getA(i/P) + getA(i/Q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P >> Q;
    A[0] = 1;
    cout << getA(N);

    return 0;
}