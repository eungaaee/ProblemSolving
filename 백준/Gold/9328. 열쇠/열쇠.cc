#include <iostream>
#include <queue>
using namespace std;

int h, w;
char **flatmap;
bool key[26];

void bfs(int &ans) {
    queue<pair<int, int>> q, door[26];
    int d[] = {0, 0, -1, 1};

    bool **v;
    v = new bool*[h+2];
    for (int i = 0; i <= h+1; i++) {
        v[i] = new bool[w+2];
        fill(v[i], v[i]+w+2, 0);
    }

    // 패딩에서 시작
    q.push({0, 0});
    v[0][0] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + d[i];
            int nc = c + d[3-i];

            if (0 <= nr && nr <= h+1 && 0 <= nc && nc <= w+1 && !v[nr][nc]) {
                v[nr][nc] = true;

                if (flatmap[nr][nc] == '*') continue; // if wall then continue
                else if (flatmap[nr][nc] == '$') ans++; // if document then ans++
                else if ('a' <= flatmap[nr][nc] && flatmap[nr][nc] <= 'z' && !key[flatmap[nr][nc]-'a']) { // if key
                    char alphabet = flatmap[nr][nc]-'a';

                    key[alphabet] = true; // add key
                    while (!door[alphabet].empty()) { // enqueue key's doors to bfs_queue
                        q.push(door[alphabet].front());
                        door[alphabet].pop();
                    }
                } else if ('A' <= flatmap[nr][nc] && flatmap[nr][nc] <= 'Z' && !key[flatmap[nr][nc]-'A']) { // if door *LOCKED*
                    door[flatmap[nr][nc]-'A'].push({nr, nc}); // enqueue door to door_queue
                    continue; // continue!!
                }
                q.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < h+2; i++) delete[] v[i];
    delete[] v;

    for (int i = 0; i < 26; i++)
    while (!door[i].empty()) door[i].pop();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        cin >> h >> w;

        flatmap = new char*[h+2];
        for (int i = 0; i <= h+1; i++) flatmap[i] = new char[w+2];

        // map의 테두리에 패딩을 추가해서 실제 맵의 가장자리로 탐색할 수 있도록 하기
        for (int i = 0; i <= h+1; i += h+1) {
            for (int j = 0; j <= w+1; j++) {
                flatmap[i][j] = '.';
            }
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 0; j <= w+1; j += w+1) {
                flatmap[i][j] = '.';
            }
        }

        // input map
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> flatmap[i][j];
            }
        }

        // input keys
        string temp;
        cin >> temp;
        for (char c : temp) {
            if (c == '0') break;
            key[c-'a'] = 1;
        }

        // find
        int ans = 0;
        bfs(ans);
        cout << ans << '\n';

        for (int i = 0; i < h+2; i++) delete[] flatmap[i];
        delete[] flatmap;

        fill(key, key+26, 0);
    }

    return 0;
}