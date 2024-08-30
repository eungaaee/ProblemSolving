#include <stdio.h>
#include <string.h>
int main() {
	char s[101];
	int k, x=1;
	gets(s);
	k = strlen(s)-1;
	for (int i=0; i<k; i++) {
		if (s[i]!=s[k-i]) {
			x=0;
			break;
		}
	}
	printf("%d", x);
}