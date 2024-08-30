#include <iostream>
#include <algorithm>
using namespace std;

long long home[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; // 차원, 개수
    cin >> N >> M;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> home[j][i];

    long long F[1000];
    for (int i = 0; i < N; i++) {
        sort(home[i], home[i]+M);
        if (M%2) F[i] = home[i][M/2];
        else F[i] = home[i][M/2] + home[i][M/2-1] >> 1;
    }

    long long sum = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            sum += abs(F[j]-home[j][i]);

    cout << sum << '\n';
    for (int i = 0; i < N; i++) cout << F[i] << ' ';

    return 0;
}