#include <stdio.h>
#include <string.h>
int main() {
	int n, gcnt, slen;
	char cur, prev='?';
	scanf("%d", &n);
	gcnt = n;
	for (int i=0; i<n; i++) {
		char s[101];
		int cnt[26] = {0};
		scanf("%s", s);
		slen = strlen(s);
		for (int j=0; j<slen; j++) {
			cur = s[j];
			if (cur!=prev&cnt[cur-97]!=0) {
				gcnt--;
				break;
			}
			cnt[cur-97]++;
			prev = cur;
		}
	}
	printf("%d", gcnt);
}