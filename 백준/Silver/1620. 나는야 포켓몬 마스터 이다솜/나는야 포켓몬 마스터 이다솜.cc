// 배열->인덱스 and 이진탐색 -> 정렬해야하는데 정렬하면 숫자로 접근 하는것도 다시 짜야함.
// 해시맵을 통한 접근
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n, m, searchN;
    vector<string> clct;
    map<string, int> clctMap;
    char search[21];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", search);
        clct.push_back(search);
        clctMap.insert(make_pair(search, i + 1));
    }
    for (int i = 0; i < m; i++) {
        searchN = 0;
        scanf("%s", search);
        if (search[0] >= '0' && search[0] <= '9') {
            cout << clct[stoi(search) - 1] << '\n';
        } else {
            printf("%d\n", clctMap[search]);
        }
    }
    return 0;
}