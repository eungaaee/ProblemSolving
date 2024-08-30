#include <iostream>
using namespace std;
int main() {
    int n, *scores, *maxScores;
    cin >> n;
    scores = new int[n];
    maxScores = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }
    maxScores[0] = scores[0];
    maxScores[1] = scores[0] + scores[1];
    maxScores[2] = scores[2] + (scores[0] > scores[1] ? scores[0] : scores[1]);
    for (int i = 3; i < n; i++) {
        maxScores[i] = scores[i] + (scores[i - 1] + maxScores[i - 3] > maxScores[i - 2] ? scores[i - 1] + maxScores[i - 3] : maxScores[i - 2]);
    }
    cout << maxScores[n - 1];
    delete[] scores;
    delete[] maxScores;
    return 0;
}