#include <malloc.h>
#include <iostream>
using namespace std;
int main() {
    int n, k, *values, c = 0;
    cin >> n >> k;
    values = (int*)malloc(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    while (k) {
        --n;
        if (k >= values[n]) {
            c += k / values[n];
            k %= values[n];
        }
    }
    cout << c;
    return 0;
}