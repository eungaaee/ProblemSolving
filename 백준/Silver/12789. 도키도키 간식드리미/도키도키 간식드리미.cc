#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, line[1000];
    stack<int> side;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> line[i];

    int i = 0, p = 1;
    while (1) {
        if (line[i] == p) i++, p++;
        else if (!side.empty() && side.top() == p) side.pop(), p++;
        else if (i < N) side.push(line[i]), i++;
        else if (side.empty()) break;
        else {
            cout << "Sad";
            return 0;
        }
    }
    cout << "Nice";
    return 0;
}