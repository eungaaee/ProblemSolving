#include <stdio.h>
#define ull unsigned long long

int main() {
    int X, Y, W, S;
    ull min;
    scanf("%d%d%d%d", &X, &Y, &W, &S);
    min = (ull)(W<<1<S ? W<<1:S)*(X < Y ? X : Y);
    if (X<Y) X = Y-X;
    else X = X-Y;
    min += W < S ? (ull)W*X : (ull)S*(X-X%2)+W*(X%2);
    printf("%llu", min);
    return 0;
}