#include <malloc.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n, *pi, t = 0, left, right, mid;
    cin >> n;
    pi = (int*)malloc(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> pi[i];
    }
    sort(pi, pi+n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            t += pi[j];
        }
    }
    cout << t;
    return 0;
}