#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, num;
    cin >> N;
    int cards[N];
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    sort(cards, cards + N);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        int left = 0, right = N-1;
        bool isFound = 0;
        while (left <= right) {
            int mid = (left+right)/2;
            if (cards[mid] == num) {
                isFound = 1;
                break;
            } else if (cards[mid] < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (isFound) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    return 0;
}