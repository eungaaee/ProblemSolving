#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Grades {
    string name;
    int kor;
    int eng;
    int math;
};

bool compare(Grades a, Grades b) {
    if (a.kor != b.kor) return a.kor > b.kor;
    else if (a.eng != b.eng) return a.eng < b.eng;
    else if (a.math != b.math) return a.math > b.math;
    else return a.name < b.name;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Grades> s(N);
    for (int i = 0; i < N; i++)
        cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].math;

    sort(s.begin(), s.end(), compare);
    for (int i = 0; i < N; i++) cout << s[i].name << '\n';

    return 0;
}