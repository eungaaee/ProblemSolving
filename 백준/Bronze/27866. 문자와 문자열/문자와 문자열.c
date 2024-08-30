#include <stdio.h>
int main() {
	char s[1000];
	int i;
	scanf("%s%d", &s,&i);
	printf("%c", s[i-1]);
}