#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int h[n+1];
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        h[n] = -1;

        stack<int> s;
        long long max_area = 0;

        for (int i = 0; i <= n; i++) {
            int width, height;
            while (!s.empty() && h[i] < h[s.top()]) {
                height = h[s.top()];
                s.pop();
                if (s.empty()) width = i;
                else width = i - s.top() - 1;

                if ((long long)width * height > max_area) {
                    max_area = (long long)width * height;
                }
            }

            s.push(i);
        }

        cout << max_area << '\n';
    }

    return 0;
}