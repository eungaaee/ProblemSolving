#include <stdio.h>
#include <string.h>
int main() {
	char s[101];
	int c, k;
	gets(s);
	c = strlen(s);
	k = c;
	for (int i=0; i<k; i++) {
		if (s[i]=='=') {
			if (s[i-1]=='c')
				c--;
			else if (s[i-1]=='s')
				c--;
			else if (s[i-1]=='z') {
				c--;
				if (s[i-2]=='d')
					c--;
			}
		} else if (s[i]=='-') {
			if (s[i-1]=='c')
				c--;
			else if (s[i-1]=='d')
				c--;
		} else if (s[i]=='j') {
			if (s[i-1]=='l')
				c--;
			else if (s[i-1]=='n')
				c--;
		}
	}
	printf("%d", c);
}