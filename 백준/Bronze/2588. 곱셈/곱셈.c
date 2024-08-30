#include <stdio.h>
int main(a,b) {
    scanf("%d%d", &a,&b);
    printf("%d %d %d %d", a*(b%10), a*(b%100-b%10)/10, a*(b-b%100)/100, a*b);
}