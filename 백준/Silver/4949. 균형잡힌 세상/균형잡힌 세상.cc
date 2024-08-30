#include <cstdio>
#include <stack>
int main() {
    char str[102];
    bool isMatch;
    std::stack<char> s;
    while (1) {
        fgets(str, 102, stdin);
        if (str[0] == '.' && str[2] == '\0') {
            break;
        }
        isMatch = 1;
        for (int i = 0; str[i] != '\n'; i++) {
            if (str[i] == '(') {
                s.push('s');
            } else if (str[i] == '[') {
                s.push('l');
            } else if (str[i] == ')') {
                if (!s.empty() && s.top() == 's') {
                    s.pop();
                } else {
                    isMatch = 0;
                    break;
                }
            } else if (str[i] == ']') {
                if (!s.empty() && s.top() == 'l') {
                    s.pop();
                } else {
                    isMatch = 0;
                    break;
                }
            }
        }
        puts(isMatch && s.empty() ? "yes" : "no");
        while (!s.empty()) {
            s.pop();
        }
    }
    return 0;
}