#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string name1, name2;
    set<string> rainbow{"ChongChong"};
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> name1 >> name2;
        if (rainbow.count(name1) & !rainbow.count(name2)) rainbow.insert(name2);
        else if (rainbow.count(name2) & !rainbow.count(name1)) rainbow.insert(name1);
    }
    cout << rainbow.size();
    return 0;
}