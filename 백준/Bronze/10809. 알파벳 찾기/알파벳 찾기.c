#include <stdio.h>
int main() {
	char s[100];
	int e, l;
	scanf("%s", s);
	for (e=0; s[e]!='\0'; e++);
	for (int i = 97; i < 123; i++) {
		for (int j = 0; j < e; j++) {
			if ((char)i==s[j]) {
				l = j;
				break;
			} else {
				l = -1;
			}
		}
		printf("%d ", l);
	}
}