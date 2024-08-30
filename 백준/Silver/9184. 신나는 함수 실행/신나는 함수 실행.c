#include <stdio.h>

int w(int a, int b, int c) {
    static int warr[101][101][101];
    if (warr[a+50][b+50][c+50] > 0) return warr[a+50][b+50][c+50];
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    else if (a > 20 || b > 20 || c > 20) return warr[70][70][70] = w(20, 20, 20); 
    else if (a < b && b < c) return (warr[a+50][b+50][c+49] = w(a, b, c-1)) + (warr[a+50][b+49][c+49] = w(a, b-1, c-1)) - (warr[a+50][b+49][c+50] = w(a, b-1, c));
    else return (warr[a+49][b+50][c+50] = w(a-1, b, c)) + (warr[a+49][b+49][c+50] = w(a-1, b-1, c)) + (warr[a+49][b+50][c+49] = w(a-1, b, c-1)) - (warr[a+49][b+49][c+49] = w(a-1, b-1, c-1));
}

int main() {
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c)) {
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
    return 0;
}