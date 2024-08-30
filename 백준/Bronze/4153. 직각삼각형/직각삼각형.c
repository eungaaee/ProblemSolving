#include <stdio.h>
int main() {
	int a, b, c, min, max;
	scanf("%d%d%d", &a, &b, &c);
	while (a+b+c>0) {
		min = a<b?b<c?a:a<c?a:c:a<c?b:b<c?b:c;
		max = a>b?b>c?a:a>c?a:c:a>c?b:b>c?b:c;
		printf("%s\n", max*max==min*min+(a+b+c-min-max)*(a+b+c-min-max)?"right":"wrong");
		scanf("%d%d%d", &a, &b, &c);
	}
}