#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();

    for (int pID = 1; pID <= T; pID++) {
        cout << "PROGRAM #" << pID << ":\n";

        // 프로그램의 코드 걸러내기
        string code = "";

        while (true) {
            string temp;
            getline(cin, temp);
            if (temp == "end") break;

            for (char& c: temp) {
                if (c == ' ') continue;
                else if (c == '%') break;
                code += c;
            }
        }

        // [, ] 검사 및 서로의 위치 기록
        stack<int> open_idx;
        int bracket[128000];
        int idx = 0;
        bool is_alone = false;

        for (char& c: code) {
            if (c == '[') open_idx.push(idx);
            else if (c == ']') {
                if (open_idx.empty()) { // 짝이 없는 ]가 생기면 COMPILE ERROR
                    is_alone = true;
                    break;
                }

                bracket[idx] = open_idx.top();
                bracket[open_idx.top()] = idx;
                open_idx.pop();
            }

            idx++;
        }

        if (!open_idx.empty()) is_alone = true; // 짝이 없는 [가 생기면 COMPILE ERROR

        // 파싱
        if (is_alone) {
            cout << "COMPILE ERROR\n";
            continue;
        }

        unsigned char byte_arr[32768] = {};
        int ptr = 0;

        for (int i = 0; i < code.size(); i++) {
            switch (code[i]) {
                case '>':
                    ptr++;
                    if (ptr > 32767) ptr = 0;
                    break;
                case '<':
                    ptr--;
                    if (ptr < 0) ptr = 32767;
                    break;
                case '+':
                    byte_arr[ptr]++; // unsigned char 이므로 자동 순환
                    break;
                case '-':
                    byte_arr[ptr]--;
                    break;
                case '.':
                    cout << byte_arr[ptr];
                    break;
                case '[':
                    if (byte_arr[ptr] == 0) i = bracket[i];
                    break;
                case ']':
                    if (byte_arr[ptr] != 0) i = bracket[i];
                    break;
            }
        }
        cout << '\n';
    }

    return 0;
}