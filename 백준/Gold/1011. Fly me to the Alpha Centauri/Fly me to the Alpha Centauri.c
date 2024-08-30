#include <stdio.h>
#include <math.h>

int f(int x, int y) {
    double root = sqrt(y-x);
    int iroot = root;
    if (root == iroot) return root*2 - 1; // 제곱수일 때
    else if (y-x <= iroot*iroot+iroot) return iroot*2;
    else return iroot*2 + 1;
}

int main() {
    int T, x, y;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", f(x, y));
    }
    return 0;
}