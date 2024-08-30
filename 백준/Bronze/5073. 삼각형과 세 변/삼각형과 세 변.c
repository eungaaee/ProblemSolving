#include <stdio.h>
int main() {
	int a, b, c, m;
	while(1) {
		scanf("%d%d%d", &a, &b, &c);
		if (!(a+b+c))
			break;
		m = a>b?b>c?a:a>c?a:c:a>c?b:b>c?b:c;
		puts(a+b+c-m<=m?"Invalid":a==b&&b==c?"Equilateral":(a-b)*(b-c)*(c-a)?"Scalene":"Isosceles");
	}
}