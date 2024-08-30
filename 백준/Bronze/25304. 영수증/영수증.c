#include <stdio.h>
int main(x,n) {
	int t=0, a, b;
	scanf("%d%d", &x,&n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a,&b);
		t += a*b;
	}
	printf("%s", x==t?"Yes":"No");
}