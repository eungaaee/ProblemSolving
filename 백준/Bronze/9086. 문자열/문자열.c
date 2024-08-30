#include <stdio.h>
int main() {
	int t, j;
	char s[1000];
	scanf("%d", &t);
	for (int i=0; i<t; i++) {
		scanf("%s", s);
		for (j=0; s[j]!='\0'; j++);
		printf("%c%c ", s[0],s[j-1]);
	}
}