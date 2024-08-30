#include <stdio.h>
int main() {
	char stra[4], strb[4];
	int a=0, b=0, p=1;
	scanf("%s%s", stra,strb);
	for (int i=0; i<3; i++,p*=10) {
		a += (stra[i]-48)*p;
		b += (strb[i]-48)*p;
	}
	printf("%d", a>b?a:b);
}