#include <stdio.h>
int main() {
	int a, b, t, x;
	scanf("%d %d", &t, &b);
	a = t<b?t:b;
	b = t>b?t:b;
	x = a*b;
	while (t) {
		t = b%a;
		b = a;
		a = t;
	}
	printf("%d\n%d", b, x/b);
}