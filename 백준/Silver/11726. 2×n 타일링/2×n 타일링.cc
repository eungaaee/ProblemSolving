#include <iostream>
using namespace std;
int main() {
    int n, *arr;
    cin >> n;
    arr = new int[n];
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 2; i < n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }
    cout << arr[n - 1];
    return 0;
}