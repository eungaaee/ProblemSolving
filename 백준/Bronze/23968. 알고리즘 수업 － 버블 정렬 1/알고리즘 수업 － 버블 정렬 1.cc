#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int arr[10000];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int cnt = 0;
    for (int i = N-1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            if (arr[j-1] > arr[j]) arr[j-1]^=arr[j], arr[j]^=arr[j-1], arr[j-1]^=arr[j], cnt++;
            if (cnt == K) {
                cout << arr[j-1] << ' ' << arr[j];
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}