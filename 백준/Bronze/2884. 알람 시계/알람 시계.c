#include <stdio.h>
int main(a,b) {
	scanf("%d%d", &a,&b);
	printf("%d %d", b>=45?a:a>=1?a-1:23, b>=45?b-45:b+15);
}