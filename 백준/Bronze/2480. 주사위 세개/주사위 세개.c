#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d", a==b&b==c?(10+a)*1000:(a-b)*(b-c)*(c-a)?(a>b?a>c?a:c:b>c?b:c)*100:(a-b?c:a)*100+1000);
}