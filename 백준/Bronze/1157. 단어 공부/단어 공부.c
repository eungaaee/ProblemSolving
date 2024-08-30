#include <stdio.h>
#include <string.h>
int main() {
	char s[1000001];
	int n[26] = {0};
	int max=0, size;
	char ans;
	scanf("%s", s);
	size = strlen(s);
	for (int i=0; i<size; i++) {
		s[i]>='a'?n[s[i]-'a']++:n[s[i]-'A']++;
	}
	for (int i=0; i<26; i++) {
		if (n[i]>max) {
			max = n[i];
			ans = i+'A';
		} else if (n[i]==max) {
			ans = '?';
		}
	}
	printf("%c", ans);
}