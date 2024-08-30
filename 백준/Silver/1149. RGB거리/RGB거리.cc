#include <iostream>
using namespace std;
int main() {
    int n, arr[1001][3], r, g, b, min{0x3f3f3f3f};
    cin >> n;
    cin >> arr[0][0] >> arr[0][1] >> arr[0][2];
    for (int i = 1; i < n; i++) {
        cin >> r >> g >> b;
        arr[i][0] = arr[i - 1][1] < arr[i - 1][2]
                        ? r + arr[i - 1][1]
                        : r + arr[i - 1][2];
        arr[i][1] = arr[i - 1][0] < arr[i - 1][2]
                        ? g + arr[i - 1][0]
                        : g + arr[i - 1][2];
        arr[i][2] = arr[i - 1][0] < arr[i - 1][1]
                        ? b + arr[i - 1][0]
                        : b + arr[i - 1][1];
    }
    for (int i = 0; i < 3; i++) {
        if (arr[n - 1][i] < min)
            min = arr[n - 1][i];
    }
    cout << min;
    return 0;
}