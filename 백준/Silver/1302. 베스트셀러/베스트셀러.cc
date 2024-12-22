#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    string book[N+1];
    for (int i = 0; i < N; i++) {
        cin >> book[i];
    }
    sort(book, book+N);
    book[N] = "";

    int count = 1, max_count = 1, max_idx = 0;
    for (int i = 1; i <= N; i++) {
        if (book[i] == book[i-1]) {
            count++;
        } else {
            if (count > max_count) {
                max_count = count;
                max_idx = i-1;
            }
            count = 1;
        }
    }

    cout << book[max_idx];

    return 0;
}