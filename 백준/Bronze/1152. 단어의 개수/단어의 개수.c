#include <stdio.h>
int main() {
	char s[1000000];
	int c=0;
	gets(s);
	for (int i=0; s[i]!='\0'; i++) {
		c -= i==0 & s[i]==' ' & s[i+1]=='\0';
		c += s[i]==' ' & i!=0 & s[i+1]!='\0';
	}
	printf("%d", c+1);
}