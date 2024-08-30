#include <cstdio>
int main() {
    int n, len, c;
    char s[51];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        len = 0;
        c = 0;
        scanf("%s", s);
        while (s[len] != '\0') {
            if (s[len] == '(') {
                c++;
            } else if (s[len] == ')') {
                c--;
            }
            if (c < 0) {
                break;
            }
            len++;
        }
        if (c == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}