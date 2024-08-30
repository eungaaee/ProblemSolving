#include <stdio.h>
int main() {
	int a, b, c, m;
	scanf("%d%d%d", &a,&b,&c);
	m = a>b?b>c?a:a>c?a:c:a>c?b:b>c?b:c;
	printf("%d", a+b+c-m>m?a+b+c:a+b+c-m+a+b+c-m-1);
}